#include "ThreadTempCPU.h"
#include "Window.h"
#include <QFile>
#include <QDebug>
#include <QtNumeric>
#include <QString>

ThreadTempCPU::ThreadTempCPU(QObject *parent) : QThread(parent) {

}
void ThreadTempCPU::run(){
    while(true){
        double temperature = getTemperature();
        emit temperatureUpdated(temperature);
        QThread::msleep(1000);
    }
}
double ThreadTempCPU::getTemperature(){
    QFile file("/sys/class/thermal/thermal_zone0/temp");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0; // handle error
    }
    QTextStream stream(&file);
    double temperature = stream.readAll().toDouble();
   // qDebug(temperature);
    file.close();
    return temperature;
}
