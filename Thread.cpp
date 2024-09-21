#include "Thread.h"
#include "Window.h"
#include <QFile>
#include <QDebug>
#include <QtNumeric>
#include <QTextStream>
#include <QString>
#include <QRegularExpression>

Thread::Thread(QObject *parent) : QThread(parent) {

}
void Thread::run(){
    while(!isInterruptionRequested()){
        double usagecpu = getUsagecpu();
        double temperature = getTemperature();
        emit usagecpuUpdated(usagecpu);
        emit temperatureUpdated(temperature);
        QThread::msleep(1000);
    }
}
double Thread::getTemperature(){
    QFile file("/sys/class/thermal/thermal_zone0/temp");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0; // handle error
    }
    QTextStream stream(&file);
    double temperature = stream.readAll().toDouble();
    file.close();
    return temperature;
}
double Thread::getUsagecpu(){
    QFile file("/proc/stat");

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0;
    }
    QTextStream stream(&file);
    QString line = stream.readLine();

    QStringList cpuValues = line.split(QRegularExpression("\\s+"));
    double idle1 = cpuValues.at(4).toDouble();
    double total1 = cpuValues.at(1).toDouble()+cpuValues.at(2).toDouble()+cpuValues.at(3).toDouble()+cpuValues.at(4)
    .toDouble()+cpuValues.at(5).toDouble()+cpuValues.at(6).toDouble()+cpuValues.at(7).toDouble();
    file.close();
    QThread::msleep(1000);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0;
    }
    QTextStream stream2(&file);
    line = stream2.readLine();
    cpuValues = line.split(QRegularExpression("\\s+"));

    double total2 = cpuValues.at(1).toDouble()+cpuValues.at(2).toDouble()+cpuValues.at(3).toDouble()+cpuValues.at(4)
    .toDouble()+cpuValues.at(5).toDouble()+cpuValues.at(6).toDouble()+cpuValues.at(7).toDouble();
    file.close();


    double usagecpu = ((total2 - total1)-(cpuValues.at(4).toDouble()-idle1) )/ (total2-total1) * 100.0;
    return usagecpu;
}
