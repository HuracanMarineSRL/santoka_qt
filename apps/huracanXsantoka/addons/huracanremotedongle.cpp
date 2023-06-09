#include "huracanremotedongle.h"
#include "QDebug"
#include <iostream>

HuracanRemoteDongle::HuracanRemoteDongle(QObject *parent) : QThread(parent)
{
    // comunication with dongle
    serial = std::make_shared<QSerialPort>("/dev/ttyUSB0");
    serial->open(QIODevice::ReadWrite);

    //serialport.writeData("bellavita\n", );
}

void HuracanRemoteDongle::run()
{
    while(true){
        char * data = new char[100];
        if(serial->bytesAvailable() > 0){
            qint64 lineLength = serial->read(data, 100);
            data[lineLength] = 0;
            std::cout << data;
        }else{
            QThread::sleep(2);
        }
        delete data;
    }
}
