#include "iomodule.h"
#include <QDebug>


IOmodule::IOmodule()
{    
    digitalDirection = 0;
    digitalValue = 0;

}


void IOmodule::update(){
    getDigitalDirectionArray();
    getDigitalValueArray();

    qDebug() << "Digital ports are: ";
    for (int i=0; i < digitalValueArray.size(); i++)
        qDebug() << digitalValueArray.at(i);

    emit updated();
}
