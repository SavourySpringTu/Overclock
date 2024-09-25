#include "Monitor.h"
#include "Thread.h"
#include "Global.h"
#include <QInputDialog>
#include <QProcess>
#include <QScreen>

Monitor::Monitor(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 300);

    label_cpuTemp = new QLabel("Temperature", this);
    label_cpuTemp->setAlignment(Qt::AlignRight);
    label_cpuTemp->setFixedHeight(25);
    label_cpuTemp->setFixedWidth(100);

    label_cpuUse = new QLabel("Usage", this);
    label_cpuUse->setAlignment(Qt::AlignRight);
    label_cpuUse->setFixedHeight(25);
    label_cpuUse->setFixedWidth(100);

    label_cpuClock = new QLabel("Clocks", this);
    label_cpuClock->setAlignment(Qt::AlignRight);
    label_cpuClock->setFixedHeight(25);
    label_cpuClock->setFixedWidth(100);

    textedit_cpuUse = new QTextEdit(this);
    textedit_cpuUse->setFixedHeight(25);
    textedit_cpuUse->setFixedWidth(100);
    textedit_cpuUse->setReadOnly(true);
    textedit_cpuUse->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_cpuTemp = new QTextEdit(this);
    textedit_cpuTemp->setFixedHeight(25);
    textedit_cpuTemp->setFixedWidth(100);
    textedit_cpuTemp->setReadOnly(true);
    textedit_cpuTemp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    textedit_cpuClock = new QTextEdit(this);
    textedit_cpuClock->setFixedHeight(25);
    textedit_cpuClock->setFixedWidth(100);
    textedit_cpuClock->setReadOnly(true);
    textedit_cpuClock->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    label_ramClock = new QLabel("Clocks", this);
    label_ramClock->setAlignment(Qt::AlignRight);
    label_ramClock->setFixedHeight(25);
    label_ramClock->setFixedWidth(100);

    label_ramUse = new QLabel("Usage", this);
    label_ramUse->setAlignment(Qt::AlignRight);
    label_ramUse->setFixedHeight(25);
    label_ramUse->setFixedWidth(100);

    textedit_ramClock = new QTextEdit(this);
    textedit_ramClock->setFixedHeight(25);
    textedit_ramClock->setFixedWidth(100);
    textedit_ramClock->setReadOnly(true);
    textedit_ramClock->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_ramUse = new QTextEdit(this);
    textedit_ramUse->setFixedHeight(25);
    textedit_ramUse->setFixedWidth(100);
    textedit_ramUse->setReadOnly(true);
    textedit_ramUse->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    processorGroup = new QGroupBox("Processor", this);
    QGridLayout *layoutProcessor = new QGridLayout(processorGroup);
    layoutProcessor->addWidget(label_cpuTemp, 0, 0);
    layoutProcessor->addWidget(textedit_cpuTemp, 0, 1);
    layoutProcessor->addWidget(label_cpuClock, 0, 2);
    layoutProcessor->addWidget(textedit_cpuClock, 0, 3);
    layoutProcessor->addWidget(label_cpuUse, 1, 0);
    layoutProcessor->addWidget(textedit_cpuUse, 1, 1);
    layoutProcessor->setAlignment(label_cpuTemp, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_cpuUse, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_cpuClock, Qt::AlignLeft);
    processorGroup->setLayout(layoutProcessor);

    ramGroup = new QGroupBox("RAM", this);
    QGridLayout *layoutRAM = new QGridLayout(ramGroup);
    layoutRAM->addWidget(label_ramClock, 0, 0);
    layoutRAM->addWidget(textedit_ramClock, 0, 1);
    layoutRAM->addWidget(label_ramUse, 1, 0);
    layoutRAM->addWidget(textedit_ramUse, 1, 1);
    layoutRAM->setAlignment(label_ramUse, Qt::AlignLeft);
    layoutRAM->setAlignment(label_ramClock, Qt::AlignLeft);
    ramGroup->setLayout(layoutRAM);

    for (int i = 0; i < 5; ++i) {
        layoutProcessor->setColumnStretch(i, 1);
        layoutRAM->setColumnStretch(i, 1);
    }

    mainLayout->addWidget(processorGroup);
    mainLayout->addWidget(ramGroup);

    setLayout(mainLayout);
    getClockRAM();
    thread = new Thread(this);
    connect(thread, &Thread::temperatureUpdated, this, &Monitor::updateTemperatureCPU);
    connect(thread, &Thread::usagecpuUpdated, this, &Monitor::updateUsageCPU);
    connect(thread, &Thread::usageramUpdated, this, &Monitor::updateUsageRAM);
    connect(thread, &Thread::clockcpuUpdated, this, &Monitor::updateClockCPU);
    thread->start();
}

void Monitor::updateTemperatureCPU(double temperature) {
    int roundedTemperature = qRound(temperature / 1000);
    QString temperatureString = QString("%1°C").arg(roundedTemperature);
    textedit_cpuTemp->setText(temperatureString);
}

void Monitor::updateUsageCPU(double usagecpu) {
    double roundedUsagecpu = qRound(usagecpu);
    QString usagecpuString = QString("%1%").arg(roundedUsagecpu);
    textedit_cpuUse->setText(usagecpuString);
}
void Monitor::updateUsageRAM(double usageram) {
    double roundedUsagecpu = qRound(usageram);
    QString usagecpuString = QString("%1%").arg(roundedUsagecpu);
    textedit_ramUse->setText(usagecpuString);
}
void Monitor::getClockRAM() {
    QProcess process;
    QStringList arguments;
    QString speeds;
    arguments << "-S" << "dmidecode" << "--type" << "memory";

    process.start("sudo", arguments);
    if (process.waitForStarted()) {
        process.write((globalVar + "\n").toLocal8Bit());
        process.closeWriteChannel();

        if (process.waitForFinished()) {
            QString output = process.readAllStandardOutput();
            QStringList lines = output.split('\n');
            for (const QString &line : lines) {
                if (line.contains("Configured Memory Speed:")) {
                    speeds = line.split(':').last().trimmed().split(' ').first()+" Hz";
                    break;
                }
            }
            textedit_ramClock->setText(speeds);
        }
    }
    textedit_ramClock->setText(speeds);
}
void Monitor:: updateClockCPU(double clockcpu){
    double roundedClockcpu = qRound(clockcpu);
    QString clockcpuString = QString("%1%").arg(roundedClockcpu);
    textedit_cpuClock->setText(clockcpuString);
}
Thread* Monitor::getThread() const {
    if (thread) {
        return thread;
    }
    return nullptr;
}
