//Lotus
#include "engine_port.h"

engine_port::engine_port()
{
    // Connect for error checks
    /*connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(connectionError(QAbstractSocket::SocketError)));

    connect(&m_socket, SIGNAL(connected()),
            this, SLOT(connect_engine()));

    connect(&m_socket, SIGNAL(stateChanged ( QAbstractSocket::SocketState )),
            this, SLOT(state_change(QAbstractSocket::SocketState)));
            */
    stopped = true;
    cstopped = true;
    vstopped = true;
    bstopped=true;
    rate = RATE;
    channels = CHANNELS;
    seconds = 10;
    alertCount = 0;
    clickFile.setFileName(soundDir+clickf);
    vFile.setFileName(soundDir+vf);
    bFile.setFileName(soundDir+bf);
    qRegisterMetaType<QtMsgType>();
}

engine_port::~engine_port() {
    if(pcm_handle != NULL) {
        end();
    }
}

void engine_port::end() {
    emit debugMsg(QtDebugMsg, Name, "Clearing sound resources...");
    snd_pcm_drain(pcm_handle);
    snd_pcm_close(pcm_handle);
    if(!stopped) {
        stopped = true;
        free(buff);
        file.close();
    }
    if(!cstopped) {
        cstopped = true;
        free(buff);
        clickFile.close();
    }
    if(!vstopped) {
        vstopped = true;
        free(buff);
        vFile.close();
    }
}

void engine_port::init() {
    emit debugMsg(QtDebugMsg, Name, "Initialising sound resources...");
    /* Open the PCM device in playback mode */
    if ((pcm = snd_pcm_open(&pcm_handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) //0 instead of SND_PCM_NONBLOCK for standard mode
        //printf("ERROR: Can't open \"%s\" PCM device. %s\n", PCM_DEVICE, snd_strerror(pcm));
        emit debugMsg(QtWarningMsg, Name, "Can't open " + QString(PCM_DEVICE) + " PCM device. " + QString(snd_strerror(pcm)));

    /* Allocate parameters object and fill it with default values*/
    snd_pcm_hw_params_alloca(&params);

    snd_pcm_hw_params_any(pcm_handle, params);

    /* Set parameters */
    if ((pcm = snd_pcm_hw_params_set_access(pcm_handle, params,
                    SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
        printf("ERROR: Can't set interleaved mode. %s\n", snd_strerror(pcm));

    if ((pcm = snd_pcm_hw_params_set_format(pcm_handle, params,
                        SND_PCM_FORMAT_S16_LE)) < 0)
        printf("ERROR: Can't set format. %s\n", snd_strerror(pcm));

    if ((pcm = snd_pcm_hw_params_set_channels(pcm_handle, params, channels)) < 0)
        printf("ERROR: Can't set channels number. %s\n", snd_strerror(pcm));

    if ((pcm = snd_pcm_hw_params_set_rate_near(pcm_handle, params, &rate, 0)) < 0)
        printf("ERROR: Can't set rate. %s\n", snd_strerror(pcm));

    /* Write parameters */
    if ((pcm = snd_pcm_hw_params(pcm_handle, params)) < 0)
        printf("ERROR: Can't set harware parameters. %s\n", snd_strerror(pcm));

    /* Resume information */
    //printf("PCM name: '%s'\n", snd_pcm_name(pcm_handle));

    //printf("PCM state: %s\n", snd_pcm_state_name(snd_pcm_state(pcm_handle)));

    //nd_pcm_hw_params_get_channels(params, &tmp);
    //printf("channels: %i ", tmp);

    /*if (tmp == 1)
        printf("(mono)\n");
    else if (tmp == 2)
        printf("(stereo)\n");
    */

    //snd_pcm_hw_params_get_rate(params, &tmp, 0);
    //printf("rate: %d bps\n", tmp);
    //printf("seconds: %d\n", seconds);

    /* Allocate buffer to hold single period */
    snd_pcm_hw_params_get_period_size(params, &frames, 0);

    buff_size = frames * channels * 2 /* 2 -> sample size */;
    snd_pcm_hw_params_get_period_time(params, &tmp, NULL);
}

void engine_port::volumeChange() {
    long min, max;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    snd_mixer_selem_id_malloc(&sid);
    const char *card = "default";
    const char *selem_name = "PCM";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    double tvol;
    if(vol == 0)
        tvol = min;
    else
        tvol = 6090*log10((double) vol/86);
    snd_mixer_selem_set_playback_volume_all(elem,  (long)(tvol));

    snd_mixer_close(handle);

}

//Directory would need to be in same location
void engine_port::runSimu() {
    if(!bstopped) return;
    buff = (char *) malloc(buff_size);
    int curvol = 0; int curRPM = 0;
    stopped = false;
    emit debugMsg(QtDebugMsg, Name, "Running Engine Simulation...");
    run = true;
    while(run) {
        vol = settings.value("volume/engVol", defaultVolume).toInt();
        emit checkRPM();
        if(curvol != vol){
            volumeChange();
            curvol = vol;
        }
        if(RPM==0) {
            continue;
        }
        if(curRPM != RPM){
            setDir();
            curRPM = RPM;
        }
        if ((pcm = read(fd, buff, buff_size)) == 0) {
            emit debugMsg(QtWarningMsg, Name, "Early end of file.");
            run = false;
            break;
        }else
            buff_total += buff_size;
        if(buff_total >= (fsize-(buff_size*5))) {
            file.reset();
            buff_total=0;
        }

        if ((pcm = snd_pcm_writei(pcm_handle, buff, frames)) == -EPIPE) {
            //printf("XRUN.\n");if(curvol)
            snd_pcm_prepare(pcm_handle);
        } else if (pcm < 0) {
            printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
            emit debugMsg(QtWarningMsg, Name, "Can't write to PCM Device. " + QString(snd_strerror(pcm)));
            run = false;
            stop();
            break;
        }
        emit checkRun();
    }

    stop();
}

void engine_port::stop() {
    if(!stopped) {
        emit debugMsg(QtDebugMsg, Name, "Stopping Engine Simulation...");
        stopped = true;
        //snd_pcm_drain(pcm_handle);
        //snd_pcm_close(pcm_handle);
        free(buff);
        file.close();
        //retry();
    }
}

void engine_port::close() {
    emit finished();
}

void engine_port::click() {
    buff = (char *) malloc(buff_size);
    vol = settings.value("volume/engVol", defaultVolume).toInt();
    volumeChange();
    if(clickFile.open(QFile::ReadOnly)) {
        cfd = clickFile.handle();
        emit clicking(true);
        cstopped = false;
        for (loops = (0.2 * 1000000) / tmp; loops > 0; loops--) {

            if ((pcm = read(cfd, buff, buff_size)) == 0) {
                //printf("Early end of file.\n");
                break;
            }

            if ((pcm = snd_pcm_writei(pcm_handle, buff, frames)) == -EPIPE) {
                //printf("XRUN.\n");
                snd_pcm_prepare(pcm_handle);
            } else if (pcm < 0) {
                printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
                emit debugMsg(QtWarningMsg, Name, "Can't write to PCM Device. " + QString(snd_strerror(pcm)));
                stopClick();
                break;
            }

        }

    } else {
        emit debugMsg(QtWarningMsg, Name, "Error opening file - " + QString(clickFile.fileName()));
        printf("File failed to open!\n");
    }
    stopClick();
}

void engine_port::stopClick() {
    if(!cstopped) {
        cstopped = true;
        //snd_pcm_drain(pcm_handle);
        //snd_pcm_close(pcm_handle);
        free(buff);
        clickFile.close();
        emit clicking(false);
    }
}

void engine_port::volEffect() {
    buff = (char *) malloc(buff_size);
    vol = settings.value("volume/engVol", defaultVolume).toInt();
    volumeChange();
    if(vFile.open(QFile::ReadOnly)) {
        vfd = vFile.handle();

        vstopped = false;
        printf("playing effect\n");
        for (loops = (0.2 * 1000000) / tmp; loops > 0; loops--) {

            if ((pcm = read(vfd, buff, buff_size)) == 0) {
                //printf("Early end of file.\n");
                break;
            }

            if ((pcm = snd_pcm_writei(pcm_handle, buff, frames)) == -EPIPE) {
                //printf("XRUN.\n");
                snd_pcm_prepare(pcm_handle);
            } else if (pcm < 0) {
                printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
                emit debugMsg(QtWarningMsg, Name, "Can't write to PCM Device. " + QString(snd_strerror(pcm)));
                stopVolEffect();
                break;
            }

        }

    } else {
        emit debugMsg(QtWarningMsg, Name, "Error opening file - " + QString(vFile.fileName()));
        printf("File failed to open!\n");
    }
    stopVolEffect();
}

void engine_port::stopVolEffect() {
    if(!vstopped) {
        vstopped = true;
        //snd_pcm_drain(pcm_handle);
        //snd_pcm_close(pcm_handle);
        free(buff);
        vFile.close();
    }
}

void engine_port::setDir() {
    if(!stopped) {
        file.close();
        QString rpmName = QString(cRPM);
        QString qfileName = soundDir + rpmName + " rpm.wav";
        file.setFileName(qfileName);
        if(!file.open(QFile::ReadOnly)){
            emit debugMsg(QtWarningMsg, Name, "Error opening file - " + QString(file.fileName()));
        }
        else {
            fd = file.handle();
            fsize=file.size();
            buff_total = 0;
            run = true;
        }
    }else {
        QString rpmName = QString(cRPM);
        QString qfileName = soundDir + rpmName + " rpm.wav";
        file.setFileName(qfileName);
    }
}

void engine_port::lowBatt() {
    if(alertCount < 3){
        alertCount++;
        return;
    }
    else if(!stopped) {
        return;
    }
    else {
        alertCount = 0;
        buff = (char *) malloc(buff_size);
        vol = defaultVolume;
        volumeChange();
        if(bFile.open(QFile::ReadOnly)) {
            bfd = bFile.handle();

            bstopped = false;
            for (loops = (0.5 * 1000000) / tmp; loops > 0; loops--) {

                if ((pcm = read(bfd, buff, buff_size)) == 0) {
                    //printf("Early end of file.\n");
                    break;
                }

                if ((pcm = snd_pcm_writei(pcm_handle, buff, frames)) == -EPIPE) {
                    //printf("XRUN.\n");
                    snd_pcm_prepare(pcm_handle);
                } else if (pcm < 0) {
                    printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
                    emit debugMsg(QtWarningMsg, Name, "Can't write to PCM Device. " + QString(snd_strerror(pcm)));
                    stopVolEffect();
                    break;
                }

            }

        } else {
            emit debugMsg(QtWarningMsg, Name, "Error opening file - " + QString(vFile.fileName()));
            printf("File failed to open!\n");
        }
        stopLowBatt();
    }
}

void engine_port::stopLowBatt() {
    if(!bstopped) {
        bstopped = true;
        //snd_pcm_drain(pcm_handle);
        //snd_pcm_close(pcm_handle);
        free(buff);
        bFile.close();
    }
}

/*
bool engine_port::init(int vol) {

    volume = vol;
    devName = "Engine Sounds";
    host = "127.0.0.1";

    CurrentGear = 0;
    CurrentRPM = 2000;
    CurrentSpeed = 30;
    DeltaRPM = 0;
    Throttle = 0;
    gearsOn = false;


    GearBox_SetNumGears(DEFAULT_NUM_GEARS);
    GearBox_SetGearRatios(DEFAULT_BASE_RATIO, DEFAULT_RATIO_GROWTH, DEFAULT_GROWTH_REDUCTION);

    emit debugMsg(QtDebugMsg, devName, "Connecting to Program");

    //connect the socket
    m_socket.connectToHost(host, port);
    return 0;
}

void engine_port::close() {
    strcpy(sendbuf,"STOP");
    BytesSent = m_socket.write(sendbuf,strlen(sendbuf));
    m_socket.close();
    //BytesSent = send(SendingSocket, sendbuf, strlen(sendbuf), 0);
}

void engine_port::connect_engine(){
    emit debugMsg(QtDebugMsg, devName, "Sending Data");
    strcpy(sendbuf,"STAR");
    BytesSent = m_socket.write(sendbuf,strlen(sendbuf));
    volumeChange(volume);
}



void engine_port::sendData(int data) {
    itoa(data,sendbuf,10);
    BytesSent = m_socket.write(sendbuf,strlen(sendbuf));
    //BytesSent = send(SendingSocket, sendbuf, strlen(sendbuf), 0);
}

void engine_port::currentSend(float data) {
    if(!gearsOn) {

        float max;
        float g;
        if(data < 130) {
            max = 150;
            g = 3500/max;
        }
        else {
            max = 200;
            g = 8000/max;
        }
        int t = int(g*data + 1800);
        CurrentRPM = t;
    }
    else {
        Throttle = (0.8/400)*(data - 15);
        if(Throttle < 0) {
            Throttle = 0;
        }
        this->GearBox_Update_Auto(CurrentSpeed,Throttle);
    }

    this->sendData(CurrentRPM);

    QString q,r,s,t;
    q.setNum(this->CurrentGear);
    r.setNum(this->CurrentRPM);
    s.setNum(this->CurrentSpeed);
    t.setNum(Throttle);
    emit debugMsg(QtDebugMsg,devName,"Gear: " + q);
    emit debugMsg(QtDebugMsg,devName,"RPM: " + r);
    emit debugMsg(QtDebugMsg,devName,"Speed: " + s);
    emit debugMsg(QtDebugMsg,devName,"Throttle: " + t);
    (*)/
}

void engine_port::volumeChange(int vol) {
    //emit debugMsg(QtDebugMsg, devName, "Volume Adjustment");
    QString t;
    t.setNum(vol);
    if(vol/10 >= 1) {
        t = "0" + t;
    }
    else if (vol/10 == 0) {
        t = "00" + t;
    }
    if (vol/100 == 1) {
        t = "0" + t;
    }
    t = "V" + t;
    QByteArray n = t.toAscii();
    BytesSent = m_socket.write(n);
}

void engine_port::connectionError(QAbstractSocket::SocketError)
{
    emit debugMsg(QtCriticalMsg, devName, m_socket.errorString());
    if(m_socket.error() == 0) {
        this->init(volume);
    }
}

void engine_port::state_change(QAbstractSocket::SocketState)
{
    QString msg;
    msg.setNum(m_socket.state());
    emit debugMsg(QtCriticalMsg,devName,msg);
}

void engine_port::boot_failure() {
    emit debugMsg(QtDebugMsg,devName,"Engine Sounds Library has failed to execute");
}

void engine_port::GearBox_SetGearRatios(float Base, float Growth, float Reduction) {
        RatioBase = Base;
        RatioGrowth = Growth;
        GrowthReduction = Reduction;
        GearBox_ApplyGearRatios();
}

void engine_port::GearBox_ApplyGearRatios() {
        float b = RatioBase;
        float g = RatioGrowth;
        int i;
        for (i=0; i < 6; i++) {
                GearRatios[i] = b;
                b = b * g;
                g = g * GrowthReduction;
                // QString t;
                //t.setNum(GearRatios[i]);
                //emit debugMsg(QtDebugMsg, devName, t);
        }
}

void engine_port::GearBox_SetNumGears(int Gears) {
        NumGears = Gears;
}

void engine_port::GearBox_Update_Auto(int Speed, float Throttle) {

        // basic data update
        int OldRPM = CurrentRPM;
        CurrentSpeed = Speed;
        Throttle = Throttle;
        CurrentRPM = Speed / GearRatios[CurrentGear];
        DeltaRPM = CurrentRPM - OldRPM;

        // gear logic
        int SwitchUp = RPM_CRUISE_IDEAL + ( (RPM_MAX-RPM_MIN) * Throttle );
        int SwitchDown;
        if (Throttle < TURBO_SHIFT_DOWN_THROTTLE)
                SwitchDown = RPM_CRUISE_LOW;
        else
                SwitchDown = RPM_CRUISE_HIGH;
        if (OldRPM >= SwitchUp && CurrentGear < NumGears-1) {
                CurrentGear++;
                CurrentRPM = Speed / GearRatios[CurrentGear];
                //Audio_ClearActiveSounds();
        }
        else if (OldRPM < SwitchDown && CurrentGear > 0) {
                CurrentGear--;
                CurrentRPM = Speed /GearRatios[CurrentGear];
                //Audio_ClearActiveSounds();
        }
}
*/
