#include "Thread.h"
#include "Global.h"
#include <QFile>
#include <QDebug>
#include <QtNumeric>
#include <QTextStream>
#include <QString>
#include <QRegularExpression>

static const QRegularExpression myRegex("\\s+");
static const QRegularExpression cpuGetClockCPURegex("cpu MHz\\s+:\\s+(\\d+\\.\\d+)");
static const QRegularExpression cpuGetNameCPURegex("model name\\s+:\\s+([A-Za-z0-9 ]+)");



Thread::Thread(QObject *parent) : QThread(parent) {

}
void Thread::run(){
    while(!isInterruptionRequested()){
        double usagecpu = getPerUsageCPU();
        double temperaturecpu = getTemperatureCPU();
        double usageram = getPerUsageRAM();
        double clockcpu = getClockCPU();

        emit clockCPUUpdated(clockcpu);
        emit perUsageCPUUpdated(usagecpu);
        emit temperatureCPUUpdated(temperaturecpu);
        emit perUsageRAMUpdated(usageram);

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
double Thread::getPerUsageCPU(){
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
double Thread :: getPerUsageRAM(){
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
double Thread::getClockCPU() {
    double total = 0.0;
    int count = 0;
    QString line;
    QFile file("/proc/cpuinfo");

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return 1;
    }

    QTextStream in(&file);
    QRegularExpressionMatch match;

    do{
        line = in.readLine();
        match = cpuGetClockCPURegex.match(line);
        if (match.hasMatch()) {
            double cpuMHz = match.captured(1).toDouble();
            total += cpuMHz;
            count++;
        }
    }while(in.atEnd()==false);
    file.close();

    if (count > 0) {
        total /= count;
    } else {
        qDebug() << "No valid CPU MHz entries found.";
    }
    return total;
}
