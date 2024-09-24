#include "Thread.h"
#include "Window.h"
#include <QFile>
#include <QDebug>
#include <QtNumeric>
#include <QTextStream>
#include <QString>
#include <QRegularExpression>

static const QRegularExpression myRegex("\\s+");
QRegularExpression cpuGetClockRegex("cpu MHz\\s+:\\s+(\\d+\\.\\d+)");

Thread::Thread(QObject *parent) : QThread(parent) {

}
void Thread::run(){
    while(!isInterruptionRequested()){
        double usagecpu = getUsageCPU();
        double temperature = getTemperatureCPU();
        double usageram = getUsageRAM();

        double clockcpu = getClockCPU();
        emit usagecpuUpdated(usagecpu);
        emit temperatureUpdated(temperature);
        emit usageramUpdated(usageram);
        emit clockcpuUpdated(clockcpu);
        QThread::msleep(1000);
    }
}
double Thread::getTemperatureCPU(){
    QFile file("/sys/class/thermal/thermal_zone0/temp");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0; // handle error
    }
    QTextStream stream(&file);
    double temperature = stream.readAll().toDouble();
    file.close();
    return temperature;
}
double Thread::getUsageCPU(){
    QFile file("/proc/stat");

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0;
    }
    QTextStream stream(&file);
    QString line = stream.readLine();

    QStringList cpuValues = line.split(myRegex);
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
    cpuValues = line.split(myRegex);

    double total2 = cpuValues.at(1).toDouble()+cpuValues.at(2).toDouble()+cpuValues.at(3).toDouble()+cpuValues.at(4)
    .toDouble()+cpuValues.at(5).toDouble()+cpuValues.at(6).toDouble()+cpuValues.at(7).toDouble();
    file.close();


    double usagecpu = ((total2 - total1)-(cpuValues.at(4).toDouble()-idle1) )/ (total2-total1) * 100.0;
    return usagecpu;
}
double Thread :: getUsageRAM(){
    QFile file("/proc/meminfo");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0;
    }
    QTextStream stream(&file);
    QString lineTotal = stream.readLine();
    QString lineFree = stream.readLine();
    QStringList s1 = lineTotal.split(myRegex);
    QStringList s2 = lineFree.split(myRegex);
    return ((s1.at(1).toDouble()-s2.at(1).toDouble())/s1.at(1).toDouble())*100;
}
double Thread :: getClockCPU(){
    double  total=0;
    int count =1;
    QString line;
    QFile file("/proc/cpuinfo");
    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
        qDebug() << line; // In ra tất cả các dòng
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return 0.0;
    }

    // QTextStream in(&file);
    // QRegularExpressionMatch match;

    // while (!in.atEnd()) {
    //     line = in.readLine();
    //     match = cpuGetClockRegex.match(line);
    //     qDebug() << "Reading line:" << line; // Kiểm tra dòng đọc
    //     if (match.hasMatch()) {
    //         qDebug()<<match.captured(1).toDouble();
    //         total += match.captured(1).toDouble();
    //     }
    //     count ++;
    // }
    // file.close();
    total = total/count;
    return total;
}
