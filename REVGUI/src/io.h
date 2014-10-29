#ifndef ICON_H
#define ICON_H

#define GETZ

#include <QtCore>
#include <string>

struct IOData
{
    bool carDoor;
    bool seatBelt;
    bool handBrake;
    bool CEL;
    bool net;
    bool safetySwitch;
    double RPM;
#ifdef GETZ
    bool fuelDoor;
    double TPS;
    double AUX;
#endif
};

class IOMODULE : public QObject
{
    Q_OBJECT

public:
    IOMODULE();
    virtual ~IOMODULE();

public slots:
    bool init();
    void end();

signals:
    void updated(IOData);

private:
    IOData ioData;
    QProcess *shell;

private slots:
    void update(QString text);
    void onReadyRead();
    int getRPM();
};

#endif // ICON_H
