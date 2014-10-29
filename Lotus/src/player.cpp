#include "player.h"


Player::Player()
{
    objName = "Player";

    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);
    metaInformationResolver = new Phonon::MediaObject(this);

    Phonon::createPath(mediaObject, audioOutput);

    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));

    connect(metaInformationResolver, SIGNAL(metaDataChanged()), this, SLOT(getMetaData()));
    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(metaError(Phonon::State,Phonon::State)));

    loaded  = true;
    playing = false;

    repeatItem = defaultRepeatItem;
    repeatAll  = defaultRepeatAll;
}

void Player::loadSettings()
{
    if (!mediaObject->isValid() || !audioOutput->isValid())
        emit debugMsg(QtCriticalMsg, objName, "Phonon error - check if backend libraries are present");
    else {
        if (mediaObject->outputPaths().isEmpty())
            emit debugMsg(QtCriticalMsg, objName, "mediaObject has no output paths");
        if (audioOutput->inputPaths().isEmpty())
            emit debugMsg(QtCriticalMsg, objName, "audioOutput has no input paths");
    }

    settings.beginGroup("player");
    repeatItem = settings.value("repeatItem",defaultRepeatItem).toBool();
    repeatAll  = settings.value("repeatAll",defaultRepeatAll).toBool();
    addSources(settings.value("mediaSources").toStringList());
    selectItem(settings.value("selectedItem",0).toInt());
    audioOutput->setVolume(settings.value("volume",defaultVolume).toReal());
    settings.endGroup();

    emit debugMsg(QtWarningMsg, objName, "last settings loaded ");
}

void Player::saveSettings()
{
    QStringList mediaSources;
    for (int i=0; i<sources.length(); i++) {
        if (sources.at(i).type() == Phonon::MediaSource::LocalFile)
            mediaSources.append(sources.at(i).fileName());
        else if (sources.at(i).type() == Phonon::MediaSource::Url)
            mediaSources.append(sources.at(i).url().toString());
    }

    settings.beginGroup("player");
    settings.setValue("repeatItem",repeatItem);
    settings.setValue("repeatAll",repeatAll);
    settings.setValue("mediaSources",mediaSources);
    settings.setValue("selectedItem", sources.indexOf(mediaObject->currentSource()));
    settings.setValue("volume", audioOutput->volume());
    settings.endGroup();

    emit debugMsg(QtWarningMsg, objName, "settings saved ");
}

void Player::setDefaultSettings()
{
    deleteAll();
    repeatItem = defaultRepeatItem;
    repeatAll  = defaultRepeatAll;
    audioOutput->setVolume(defaultVolume);

    emit debugMsg(QtWarningMsg, objName, "default settings applied ");

    settings.beginGroup("player");
    settings.remove("");
    settings.endGroup();

    saveSettings();
}

void Player::addSources(QDir dir)
{
    QStringList sources;
    dir.setPath(dir.canonicalPath());
    QStringList soundFiles = dir.entryList((QDir::Files | QDir::NoDotAndDotDot | QDir::Readable),(QDir::Name));
    for (int i=0; i<soundFiles.length(); i++)
    {
        sources.append(dir.absolutePath() + "/" + soundFiles.at(i));
    }
    addSources(sources);
}

void Player::addSources(QString sourceName)
{
    addSources(QStringList(sourceName));
}


void Player::addSources(QStringList sourceNames)
{
    if (sourceNames.isEmpty())
        return;

    int index = sources.length();
    foreach (QString string, sourceNames) {
        Phonon::MediaSource newSource;
        if (string.left(7)=="http://")
            newSource = Phonon::MediaSource(QUrl(string));
        else
            newSource = Phonon::MediaSource(string);

        if (newSource.type()!=Phonon::MediaSource::Invalid)
        {
            QMap<QString, QString> metaData;
            QString sourceName;
            if (newSource.type() == Phonon::MediaSource::LocalFile){
                sourceName = newSource.fileName();
                QStringList list = sourceName.split("/");   //unix
                list = list.last().split("\\");             //windows
                sourceName = list.last();
            }
            else if (newSource.type() == Phonon::MediaSource::Url)
                sourceName = newSource.url().toString();

            metaData.insert("TITLE",sourceName);
            mediaList.append(metaData);
            sources.append(newSource);

            emit debugMsg(QtDebugMsg, objName, "added source " + sourceName);
        }
        else
            emit debugMsg(QtCriticalMsg, objName, "invalid source " + newSource.fileName());
    }
    if (index < sources.length()) //check if new sources were added
    {
        // start reading the meta data of the new sources
        metaDataIndex = index;
        metaInformationResolver->setCurrentSource(sources.at(metaDataIndex));
    }

    emit mediaListUpdated(mediaList);
}



void Player::deleteItem()
{
    int index = sources.indexOf(mediaObject->currentSource());
    deleteItem(index);
}

void Player::deleteItem(int index)
{
    emit debugMsg(QtDebugMsg, objName, "deleting source " +
                  //mediaObject->currentSource().fileName() +
                  mediaObject->currentSource().url().toString());

    // check if file is playing at the moment
    if(sources.indexOf(mediaObject->currentSource())==index){
        // select other file
        if((index+1)<sources.length())
            mediaObject->setCurrentSource(sources.at(index+1));
        else if(index>0)
            mediaObject->setCurrentSource(sources.at(index-1));
        else
            mediaObject->clear();
        stop();
    }

    // remove file from sources
    if (index < sources.length())
        sources.removeAt(index);

    // update list
    if (index < mediaList.length()){
        mediaList.removeAt(index);
        emit mediaListUpdated(mediaList);
    }

    emit selected(sources.indexOf(mediaObject->currentSource()));
}

void Player::deleteAll()
{
    emit debugMsg(QtDebugMsg, objName, "deleting all sources ");
    playing = false;
    mediaObject->clear();
    //metaInformationResolver->clear(); //crash on win xp
    sources.clear();
    mediaList.clear();
    emit mediaListUpdated(mediaList);
}

void Player::moveItemUp()
{
    int index = sources.indexOf(mediaObject->currentSource());
    int newIndex = index + 1;
    moveItem(index, newIndex);
}

void Player::moveItemDown()
{
    int index = sources.indexOf(mediaObject->currentSource());
    int newIndex = index - 1;
    moveItem(index, newIndex);
}

void Player::moveItem(int index, int newIndex)
{
    emit debugMsg(QtDebugMsg, objName, QString("moving item from %1 to %2").arg(index).arg(newIndex));

    if (index < sources.length() && index >= 0 &&
        newIndex < sources.length() && newIndex >= 0)
    {
        sources.move(index, newIndex);
        mediaList.move(index, newIndex);
        emit mediaListUpdated(mediaList);
        emit selected(sources.indexOf(mediaObject->currentSource()));
    }
}

void Player::selectItem(int index)
{
    if (index<0)
        index = 0;
    if (index < sources.length()){
        emit debugMsg(QtDebugMsg, objName, QString("selecting source number %1").arg(index));
        mediaObject->setCurrentSource(sources.at(index));
    }
}

void Player::selectItem(int row, int)
{
    selectItem(row);
}



void Player::play()
{
    emit debugMsg(QtDebugMsg, objName, "play ");
    playing = true;
    mediaObject->play();
}

void Player::pause(){
    emit debugMsg(QtDebugMsg, objName, "pause ");
    playing = false;
    mediaObject->pause();
}

void Player::stop()
{
    emit debugMsg(QtDebugMsg, objName, "stop ");
    playing = false;
    mediaObject->stop();
}

void Player::togglePlay()
{
    if (playing)
        pause();
    else
        play();
}

void Player::play(int index)
{
    selectItem(index);
    play();
}

void Player::next()
{
    int index = sources.indexOf(mediaObject->currentSource()) + 1;
    selectItem(index);
}

void Player::prev()
{
    int index = sources.indexOf(mediaObject->currentSource()) - 1;
    selectItem(index);
}




void Player::sourceChanged(Phonon::MediaSource source)
{
    emit debugMsg(QtDebugMsg, objName, "source changed to " //+ source.fileName()
                  + source.url().toString());

    emit selected(sources.indexOf(source));
}


void Player::stateChanged(Phonon::State newState, Phonon::State) // oldState)
{
    switch (newState) {
    case(Phonon::ErrorState):
        if (mediaObject->errorType() == Phonon::FatalError)
            emit debugMsg(QtFatalMsg, objName, "mediaObject fatal error: " + mediaObject->errorString());
        else
            emit debugMsg(QtCriticalMsg, objName, "mediaObject error:" + mediaObject->errorString());
        break;
    case (Phonon::PlayingState):
        emit debugMsg(QtDebugMsg, objName, "mediaObject is playing ");
        emit isPlaying(true);
        break;
    case Phonon::PausedState:
        emit debugMsg(QtDebugMsg, objName, "mediaObject is paused ");
        emit isPlaying(false);
        break;
    case Phonon::StoppedState:
        if(playing)
            mediaObject->play();    // continue playing e.g. after changing the source
        else
            mediaObject->pause();   // otherwise it keeps on playing silently
        break;
    default:
        ;
    }
}


void Player::aboutToFinish()
{
    if (repeatItem)
        mediaObject->enqueue(mediaObject->currentSource());
    else{
        int index = sources.indexOf(mediaObject->currentSource()) + 1;
        if (sources.size() > index) {
            mediaObject->enqueue(sources.at(index));
        }
        else if(repeatAll)
            mediaObject->enqueue(sources.at(0));
    }
}


void Player::getMetaData()
{
    metaDataIndex = sources.indexOf(metaInformationResolver->currentSource());
    QMap<QString, QString> metaData = metaInformationResolver->metaData();


    if (!metaData.value("TITLE").isEmpty()){
        QString title = metaData.value("TITLE").split("/").last();  //dirty hack to fix a bug in the win xp backend on the car pc
        metaData.insert("TITLE",title);
        mediaList.replace(metaDataIndex, metaData);
    }

    emit debugMsg(QtDebugMsg, objName, "finished reading meta data - " + mediaList.value(metaDataIndex).value("TITLE"));

    emit mediaListUpdated(mediaList);
    emit selected(sources.indexOf(mediaObject->currentSource()));

    // read next file
    if((metaDataIndex+1)<sources.length()){
        metaDataIndex++;
        metaInformationResolver->setCurrentSource(sources.at(metaDataIndex));
    }
}

void Player::metaError(Phonon::State newState, Phonon::State oldState)
{
    if(newState == Phonon::ErrorState && loaded)
    {
        emit debugMsg(QtCriticalMsg, objName, "Error reading meta data from " //+ metaInformationResolver->currentSource().fileName()
                      + metaInformationResolver->currentSource().url().toString());

        metaDataIndex = sources.indexOf(metaInformationResolver->currentSource());
        deleteItem(metaDataIndex);

        // read next file
        if((metaDataIndex)<sources.length())
            metaInformationResolver->setCurrentSource(sources.at(metaDataIndex));
    }

    // after a file error, next file starts with an error too
    if(newState == Phonon::ErrorState)
        loaded = !loaded;

    // loading indicates that the programm reads a new file
    if(newState == Phonon::LoadingState && oldState != Phonon::ErrorState)
        loaded = true;
}


void Player::setRepeatItem(bool repeat)
{
    repeatItem = repeat;
}

void Player::setRepeatAll(bool repeat)
{
    repeatAll = repeat;
}

bool Player::isRepeatItem()
{
    return repeatItem;
}

bool Player::isRepeatAll()
{
    return repeatAll;
}
