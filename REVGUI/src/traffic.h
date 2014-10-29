#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <QtCore>
#include "twitcurl.h"
#include <QDomDocument>

class traffic : public QObject
{
  Q_OBJECT

public:
    traffic();
    void init();
    QDomNodeList status();
    QDomNodeList date();

signals:
    void debugMsg(QtMsgType, QString, QString);

private:
    twitCurl twitterObj;
    std::string replyMsg;
    std::string tmpStr;
};

#endif // TRAFFIC_H
