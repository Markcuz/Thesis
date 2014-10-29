#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H

#define GETZ

#include <QtCore>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#ifndef LOGGER_H
static const QString defaultLogDir      = "/log_files";
static const QString defaultLogName     = "yyyy-MM-dd_hh-mm";
static const QString defaultdriver      = "Default Driver";
#endif

class DebugLogger : public QObject
{
    Q_OBJECT

public:
    DebugLogger();
    ~DebugLogger();

    void init();
    void end();
    bool checkDirSize(char* logDir);

public slots:
    void logMsg(QString msg);
    void logMsg(QtMsgType warnLevel, QString msg);
    void logMsg(QtMsgType warnLevel, QString source, QString msg);
    void newLine();

    void nameChanged();
signals:
    void displayMsg(QString msg);
    void debugMsg(QtMsgType, QString, QString);

private:
    QString objName;
    QString driverName;
    QSettings settings;
    QFile logFile;
    QTextStream logStream;
    bool logging;
};

#endif // DEBUGLOGGER_H
