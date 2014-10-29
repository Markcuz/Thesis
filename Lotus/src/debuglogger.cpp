//Lotus
#include "debuglogger.h"


DebugLogger::DebugLogger()
{
}

DebugLogger::~DebugLogger()
{
    if (logFile.isOpen()) {
        end();
    }
}

void DebugLogger::init()
{
    objName = "Logger";
    driverName = settings.value("driver",defaultdriver).toString();
    logging = true;
    //check if directory already exists
    QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
    if (!logDir.exists())
        logDir.mkpath(logDir.absolutePath());

    if(!checkDirSize(logDir.absolutePath().toUtf8().data())) {
        logging = false;
        return;
    }

    //open log file
    QDateTime startTime = QDateTime::currentDateTime();
    QString logFileName = startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".log";
    logFile.setFileName(logDir.absolutePath() + "/" + logFileName);
    logStream.setDevice(&logFile);
    if (logFile.open(QFile::WriteOnly | QFile::Text))
        logMsg("Started logging debug output to " + logFile.fileName());
    else
        logMsg("Error writing debug log file " + logFile.fileName() + " - " + logFile.errorString());

    newLine();
}

bool DebugLogger::checkDirSize(char* logDir)
{
    strcat(logDir, "/");
    DIR *dir;
    struct dirent* ent;
    struct stat st;
    char buf[PATH_MAX];
    off_t total = 0LL;

    if((dir = opendir(logDir)) == NULL)
    {
        emit debugMsg(QtWarningMsg, objName, "Checking directory size failed, couldn't open dir.");
        return false;
    }
    while((ent = readdir(dir)) != NULL)
    {
        if(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
              continue;

            sprintf(buf, "%s%s", logDir,ent->d_name);
            if(stat(buf, &st) == -1) {
                 emit debugMsg(QtWarningMsg, objName, "Error checking file stat");
                printf("Couldn't stat %s: %s\n", buf, strerror(errno));
                continue;
            }
            if(S_ISREG(st.st_mode)) {
                total += st.st_size;
            }

    }
    if(total/1024 > 100000) { //more than 100mb?
        emit debugMsg(QtWarningMsg, objName, "Directory too large, delete oldest log files.");
        return false;
    }else{
        return true;
    }

}

void DebugLogger::end()
{
    newLine();
    logMsg("Finished logging debug output to " + logFile.fileName());
    newLine();
    logFile.close();
}

void DebugLogger::nameChanged()
{
    driverName = settings.value("driver",defaultdriver).toString();
}


void DebugLogger::logMsg(QString msg)
{
    logMsg(QtDebugMsg, msg);
}


void DebugLogger::logMsg(QtMsgType warnLevel, QString msg)
{
    logMsg(warnLevel, "", msg);
}

void DebugLogger::logMsg(QtMsgType warnLevel, QString source, QString msg)
{
    if (!source.isEmpty())
        msg = "["+source+"] "+msg;

    msg = QTime::currentTime().toString("hh:mm:ss  ") + msg;

    qDebug() << msg;

    if (source != "Player" || warnLevel >= QtWarningMsg ){
    //if (warnLevel >= QtDebugMsg ){
        if(logging) {
            if (logFile.isOpen())
                logStream << driverName << "-" << msg << endl;
        }
        emit displayMsg(msg);
    }
}


void DebugLogger::newLine()
{
    if (logging) {
        if (logFile.isOpen())
            logStream << endl;
    }
    emit displayMsg(" ");
}
