#ifndef IOMODULE_H
#define IOMODULE_H

#include <QtCore>


class IOmodule : public QObject
{
Q_OBJECT
public:
    IOmodule();

protected:
    QBitArray digitalDirectionArray;
    QBitArray digitalValueArray;
    int digitalDirection;
    int digitalValue;

public slots:
    void update();
    virtual void setDigitalDirectionArray(QBitArray _digitalDirectionArray)=0;
    virtual void setDigitalValueArray(QBitArray _digitalValueArray)=0;
    virtual QBitArray getDigitalDirectionArray()=0;
    virtual QBitArray getDigitalValueArray()=0;

signals:
    void updated();

};

#endif // IOMODULE_H
