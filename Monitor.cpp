#include "Monitor.h"
#include "Thread.h"
#include "Global.h"
#include <QInputDialog>
#include <QProcess>
#include <QScreen>
#include <QFile>
#include <QPalette>

QStringList listScalingAvailabel;

Monitor::Monitor(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 400);

    label_temperatureCPU = new QLabel("Temperature", this);
    label_temperatureCPU->setAlignment(Qt::AlignRight);
    label_temperatureCPU->setFixedHeight(20);
    label_temperatureCPU->setFixedWidth(100);

    label_perUsageCPU = new QLabel("Per Usage", this);
    label_perUsageCPU->setAlignment(Qt::AlignRight);
    label_perUsageCPU->setFixedHeight(20);
    label_perUsageCPU->setFixedWidth(100);

    label_coreClockCPU = new QLabel("Core Clocks", this);
    label_coreClockCPU->setAlignment(Qt::AlignRight);
    label_coreClockCPU->setFixedHeight(20);
    label_coreClockCPU->setFixedWidth(100);

    label_usageRAM = new QLabel("Usage", this);
    label_usageRAM->setAlignment(Qt::AlignRight);
    label_usageRAM->setFixedHeight(20);
    label_usageRAM->setFixedWidth(100);

    label_perUsageRAM = new QLabel("Per Usage", this);
    label_perUsageRAM->setAlignment(Qt::AlignRight);
    label_perUsageRAM->setFixedHeight(20);
    label_perUsageRAM->setFixedWidth(100);

    label_operationMode = new QLabel("Mode", this);
    label_operationMode->setAlignment(Qt::AlignRight);
    label_operationMode->setFixedHeight(20);
    label_operationMode->setFixedWidth(100);

    label_powerConsumption = new QLabel("Power Usage", this);
    label_powerConsumption->setAlignment(Qt::AlignRight);
    label_powerConsumption->setFixedHeight(20);
    label_powerConsumption->setFixedWidth(100);

    textedit_perUsageCPU = new QTextEdit(this);
    textedit_perUsageCPU->setFixedHeight(25);
    textedit_perUsageCPU->setFixedWidth(100);
    textedit_perUsageCPU->setReadOnly(true);
    textedit_perUsageCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_temperatureCPU = new QTextEdit(this);
    textedit_temperatureCPU->setFixedHeight(25);
    textedit_temperatureCPU->setFixedWidth(100);
    textedit_temperatureCPU->setReadOnly(true);
    textedit_temperatureCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_coreClockCPU = new QTextEdit(this);
    textedit_coreClockCPU->setFixedHeight(25);
    textedit_coreClockCPU->setFixedWidth(100);
    textedit_coreClockCPU->setReadOnly(true);
    textedit_coreClockCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_usageRAM = new QTextEdit(this);
    textedit_usageRAM->setFixedHeight(25);
    textedit_usageRAM->setFixedWidth(100);
    textedit_usageRAM->setReadOnly(true);
    textedit_usageRAM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_perUsageRAM = new QTextEdit(this);
    textedit_perUsageRAM->setFixedHeight(25);
    textedit_perUsageRAM->setFixedWidth(100);
    textedit_perUsageRAM->setReadOnly(true);
    textedit_perUsageRAM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_powerConsumption = new QTextEdit(this);
    textedit_powerConsumption->setFixedHeight(25);
    textedit_powerConsumption->setFixedWidth(100);
    textedit_powerConsumption->setReadOnly(true);
    textedit_powerConsumption->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    combobox_operationMode = new QComboBox(this);
    combobox_operationMode->setFixedHeight(30);
    combobox_operationMode->setFixedWidth(150);

    // Set layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    processorGroup = new QGroupBox("Processor", this);
    QGridLayout *layoutProcessor = new QGridLayout(processorGroup);
    layoutProcessor->addWidget(label_temperatureCPU, 0, 0);
    layoutProcessor->addWidget(textedit_temperatureCPU, 0, 1);
    layoutProcessor->addWidget(label_coreClockCPU, 0, 2);
    layoutProcessor->addWidget(textedit_coreClockCPU, 0, 3);
    layoutProcessor->addWidget(label_perUsageCPU, 1, 0);
    layoutProcessor->addWidget(textedit_perUsageCPU, 1, 1);
    layoutProcessor->setAlignment(label_temperatureCPU, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_perUsageCPU, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_coreClockCPU, Qt::AlignLeft);
    processorGroup->setLayout(layoutProcessor);

    ramGroup = new QGroupBox("RAM", this);
    QGridLayout *layoutRAM = new QGridLayout(ramGroup);
    layoutRAM->addWidget(label_usageRAM, 0, 0);
    layoutRAM->addWidget(textedit_usageRAM, 0, 1);
    layoutRAM->addWidget(label_perUsageRAM, 1, 0);
    layoutRAM->addWidget(textedit_perUsageRAM, 1, 1);
    layoutRAM->setAlignment(label_perUsageRAM, Qt::AlignLeft);
    layoutRAM->setAlignment(label_usageRAM, Qt::AlignLeft);
    ramGroup->setLayout(layoutRAM);

    powerGroup = new QGroupBox("Power");
    QGridLayout *layoutPower = new QGridLayout(powerGroup);
    layoutPower->addWidget(label_powerConsumption, 0, 0);
    layoutPower->addWidget(textedit_powerConsumption, 0, 1);
    layoutPower->setAlignment(label_powerConsumption, Qt::AlignLeft);
    powerGroup->setLayout(layoutPower);

    overclockGroup = new QGroupBox("OverClock",this);
    QGridLayout *layoutOverClock = new QGridLayout(overclockGroup);
    layoutOverClock->addWidget(label_operationMode, 0, 0);
    layoutOverClock->addWidget(combobox_operationMode, 0, 1);
    layoutOverClock->setAlignment(label_operationMode, Qt::AlignLeft);
    overclockGroup->setLayout(layoutOverClock);

    getScalingAvailabel();
    for(auto i: listScalingAvailabel){
        i[0] = i[0].toUpper();
        combobox_operationMode->addItem(i);
    }
    for (int i = 0; i < 6; ++i) {
        layoutProcessor->setColumnStretch(i, 1);
        layoutRAM->setColumnStretch(i, 1);
        layoutPower->setColumnStretch(i, 1);
        layoutOverClock->setColumnStretch(i, 1);
    }
    mainLayout->addWidget(processorGroup);
    mainLayout->addWidget(ramGroup);
    mainLayout->addWidget(powerGroup);
    mainLayout->addWidget(overclockGroup);
    setLayout(mainLayout);

    getOperationMode();

    // Connection and thread
    thread = new Thread(this);
    connect(thread, &Thread::temperatureCPUUpdated, this, &Monitor::updateTemperatureCPU);
    connect(thread, &Thread::perUsageCPUUpdated, this, &Monitor::updatePerUsageCPU);
    connect(thread, &Thread::usageRAMUpdated, this, &Monitor::updatePerUsageRAMandUsageRAM);
    connect(thread, &Thread::coreClockCPUUpdated, this, &Monitor::updateCoreClockCPU);
    connect(thread, &Thread::powerConsumptionUpdated,this, &Monitor::updateConsumptionPower);

    connect(combobox_operationMode, &QComboBox::currentIndexChanged, this, &Monitor::eventChangeOperationMode);

    thread->start();
}

QColor Monitor:: colorofTemperatureCPU(double temp){
    int temp1 = temp;
    QColor color(0,0,0);
    if(temp1 <=40){
        color.setRed(0);
        color.setGreen(255);
        color.setBlue(0);
    }else if(temp1 > 40 && temp1 <=65){
        color.setRed((temp-40)*10);
        color.setGreen(255);
        color.setBlue(0);
    }else if(temp1 >65 && temp1 <=90){
        color.setGreen(255-((temp1 -65)*10));
        color.setRed(255);
        color.setBlue(0);
    }else{
        color.setRed(255);
        color.setGreen(0);
        color.setBlue(0);
    }
    return color;
}

void Monitor::updateTemperatureCPU(double temperature) {
    QString temperatureString = QString::number(temperature,'f',0)+" °C";

    // set color temperature
    QPalette palette = textedit_temperatureCPU->palette();
    palette.setColor(QPalette::Text, colorofTemperatureCPU(temperature));
    textedit_temperatureCPU->setPalette(palette);

    textedit_temperatureCPU->setText(temperatureString);
}

void Monitor::updatePerUsageCPU(double usagecpu) {
    QString usagecpuString = QString::number(usagecpu,'f',0)+" %";
    textedit_perUsageCPU->setText(usagecpuString);
}
void Monitor::updatePerUsageRAMandUsageRAM(vector<double> perUsageRAMandUsageRam) {
    QString perusageRam = QString::number(perUsageRAMandUsageRam[0], 'f', 0) +" %";
    QString usageRam =  QString::number(perUsageRAMandUsageRam[1], 'f', 0) +" MB";
    textedit_perUsageRAM->setText(perusageRam);
    textedit_usageRAM->setText(usageRam);
}
void Monitor:: updateCoreClockCPU(double clockcpu){
    QString clockcpuString = QString::number(clockcpu, 'f', 0) +" MHz";
    textedit_coreClockCPU->setText(clockcpuString);
}
void Monitor:: updateConsumptionPower(double consumptionpower){
    QString consumptionpowerString = QString::number(consumptionpower, 'f', 0) +" W";
    textedit_powerConsumption->setText(consumptionpowerString);
}
void Monitor::getScalingAvailabel(){
    QProcess process;
    process.start("bash", QStringList() << "-c" << "cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_available_governors");
    if(process.waitForStarted(1000)){
        if(process.waitForFinished(1000)){
            QByteArray output = process.readLine();
            QString line = QString::fromUtf8(output).trimmed();
            listScalingAvailabel = line.split(' ');
        }else{
            qDebug()<<"Process GetScalingAvailabel out of time!";
            process.close();
            return;
        }
    }else{
        qDebug()<<"Process GetScalingAvailabel can't start!";
        process.close();
        return ;
    }
    process.close();
    return;
}
void Monitor::getOperationMode(){
    QProcess process;
    QString command = "cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor";
    process.start("bash", QStringList() << "-c" << command);
    if(process.waitForStarted(1000)){
        if(process.waitForFinished(1000)){
            QString line = process.readLine();
            line.chop(1);
            line[0] = line[0].toUpper();
            combobox_operationMode->setCurrentText(line);
        }else{
            qDebug()<<"Process GetOperationMode out of time!";
            process.close();
            return;
        }
    }else{
        qDebug()<<"Can't start process GetOperationMode!";
        process.close();
        return;
    }
    process.close();
    return;
}
void Monitor::eventChangeOperationMode(int index) {
    QString mode = listScalingAvailabel[index];
    QString command = "echo " + PASSWORD + " | sudo -S echo && echo " + mode + " | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor";

    QProcess process;
    process.start("bash", QStringList() << "-c" << command);
    if(process.waitForStarted(1000)){
        if(process.waitForFinished(1000)){
            qDebug()<<"Precess EventChangeOperationMode Finish";
            qDebug()<<mode;
        }else{
            qDebug()<<"Process EventChangeOperationMode out of time!";
            return;
        }
    }else{
        qDebug()<<"Can't start process EventChangeOperationMode!";
        return;
    }
    process.close();
    return;
}
Thread* Monitor::getThread() const {
    if (thread) {
        return thread;
    }
    return nullptr;
}
