#include "io.h"
#include <iostream>
#include <QtCore>
#include <string>

IOMODULE::IOMODULE() : QObject()
{   
}

IOMODULE::~IOMODULE()
{
    shell->close();
    shell->terminate();
}


void IOMODULE::end()
{
    shell->close();
    shell->terminate();
}

bool IOMODULE::init()
{
    ioData.carDoor = false;
    ioData.handBrake = false;
    ioData.CEL = false;
    ioData.seatBelt = false;
    ioData.net = false;
    ioData.safetySwitch = false;
    ioData.fuelDoor = false;

    shell = new QProcess(this);
    connect(shell, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    QString program = "python3";

    QStringList arguments;
    arguments << "icons.py";

    shell->start(program,arguments);

    if (!shell->waitForStarted()) {
        exit(1);
    }

    //Tachometer signal
    /*
    tacho = new QProcess(this);
    connect(tacho, SIGNAL(readyReadTacho()), this, SLOT(onReadyRead());
    arguments.clear();
    arguments << "tacho.py";
    tacho->start(program,arguments);
    if(!tacho->waitForStarted()) {
        exit(1);
    }
    */
    return true;
}

void IOMODULE::update(QString text)
{   
    QStringList intList = text.split('\n');

    if(intList.at(0).toInt() == 1) {
        ioData.carDoor = false;
    }
    else {
        ioData.carDoor = true;
    }

    if(intList.at(1).toInt() == 1) {
        ioData.seatBelt = false;
    }
    else {
        ioData.seatBelt = true;
    }

    if(intList.at(2).toInt() == 1) {
        ioData.handBrake = false;
    }
    else {
        ioData.handBrake = true;
    }

    if(intList.at(3).toInt() == 1) {
        ioData.CEL = false;
    }
    else {
        ioData.CEL = true;
    }
/*
    if(intList.at(4) == 0) {
        ioData.safetySwitch = false;
    }
    else {
        ioData.safetySwitch = true;
    }

    if(intList.at(5) == 0) {
        ioData.fuelDoor = false;
    }
    else {
        ioData.fuelDoor = true;
    }
*/
}


int IOMODULE::getRPM()
{

    return ioData.RPM;
}

void IOMODULE::onReadyRead()
{
    QString text = shell->readAll();
    update(text);
    emit updated(ioData);
}



