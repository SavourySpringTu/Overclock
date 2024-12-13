#include "Information.h"
#include "Global.h"
#include <QVBoxLayout>
#include <QProcess>
#include <QFile>
#include <QRegularExpression>

static const QRegularExpression myRegex("^([A-Za-z]+)\\s+(.+)$");

Information::Information(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 400);

    label_nameOperatingSystem = new QLabel("Name", this);
    label_nameOperatingSystem->setAlignment(Qt::AlignLeft);
    label_nameOperatingSystem->setFixedHeight(25);
    label_nameOperatingSystem->setFixedWidth(75);

    label_versionOperatingSystem = new QLabel("Version", this);
    label_versionOperatingSystem->setAlignment(Qt::AlignLeft);
    label_versionOperatingSystem->setFixedHeight(25);
    label_versionOperatingSystem->setFixedWidth(75);

    label_nameCPU = new QLabel("Name", this);
    label_nameCPU->setAlignment(Qt::AlignLeft);
    label_nameCPU->setFixedHeight(25);
    label_nameCPU->setFixedWidth(75);

    label_coreCPU = new QLabel("Cores", this);
    label_coreCPU->setAlignment(Qt::AlignLeft);
    label_coreCPU->setFixedHeight(25);
    label_coreCPU->setFixedWidth(75);

    label_threadCPU = new QLabel("Threads", this);
    label_threadCPU->setAlignment(Qt::AlignLeft);
    label_threadCPU->setFixedHeight(25);
    label_threadCPU->setFixedWidth(75);

    label_clockRAM = new QLabel("Bus", this);
    label_clockRAM->setAlignment(Qt::AlignLeft);
    label_clockRAM->setFixedHeight(25);
    label_clockRAM->setFixedWidth(75);

    textedit_nameOperatingSystem = new QTextEdit(this);
    textedit_nameOperatingSystem->setFixedHeight(25);
    textedit_nameOperatingSystem->setFixedWidth(100);
    textedit_nameOperatingSystem->setReadOnly(true);
    textedit_nameOperatingSystem->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_versionOperatingSystem = new QTextEdit(this);
    textedit_versionOperatingSystem->setFixedHeight(25);
    textedit_versionOperatingSystem->setFixedWidth(200);
    textedit_versionOperatingSystem->setReadOnly(true);
    textedit_versionOperatingSystem->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_nameCPU = new QTextEdit(this);
    textedit_nameCPU->setFixedHeight(25);
    textedit_nameCPU->setFixedWidth(350);
    textedit_nameCPU->setReadOnly(true);
    textedit_nameCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_coreCPU = new QTextEdit(this);
    textedit_coreCPU->setFixedHeight(25);
    textedit_coreCPU->setFixedWidth(35);
    textedit_coreCPU->setReadOnly(true);
    textedit_coreCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_threadCPU = new QTextEdit(this);
    textedit_threadCPU->setFixedHeight(25);
    textedit_threadCPU->setFixedWidth(35);
    textedit_threadCPU->setReadOnly(true);
    textedit_threadCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_clockRAM = new QTextEdit(this);
    textedit_clockRAM->setFixedHeight(25);
    textedit_clockRAM->setFixedWidth(100);
    textedit_clockRAM->setReadOnly(true);
    textedit_clockRAM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    operatingSystemGroup = new QGroupBox("Operating System",this);
    QGridLayout *layoutOperatingSystem = new QGridLayout(operatingSystemGroup);
    layoutOperatingSystem->addWidget(label_nameOperatingSystem, 0, 0);
    layoutOperatingSystem->addWidget(textedit_nameOperatingSystem, 0, 1);
    layoutOperatingSystem->addWidget(label_versionOperatingSystem, 1, 0);
    layoutOperatingSystem->addWidget(textedit_versionOperatingSystem, 1, 1);
    layoutOperatingSystem->setAlignment(textedit_nameOperatingSystem, Qt::AlignLeft);
    layoutOperatingSystem->setAlignment(textedit_versionOperatingSystem, Qt::AlignLeft);
    operatingSystemGroup->setLayout(layoutOperatingSystem);

    processorGroup = new QGroupBox("Processor", this);
    QGridLayout *layoutProcessor = new QGridLayout(processorGroup);
    layoutProcessor->addWidget(label_nameCPU, 0, 0);
    layoutProcessor->addWidget(textedit_nameCPU, 0, 1);
    layoutProcessor->addWidget(label_coreCPU, 1, 0);
    layoutProcessor->addWidget(textedit_coreCPU, 1, 1);
    layoutProcessor->addWidget(label_threadCPU, 2, 0);
    layoutProcessor->addWidget(textedit_threadCPU, 2, 1);
    layoutProcessor->setAlignment(label_nameCPU, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_coreCPU, Qt::AlignLeft);
    layoutProcessor->setAlignment(label_threadCPU, Qt::AlignLeft);
    processorGroup->setLayout(layoutProcessor);

    ramGroup = new QGroupBox("RAM",this);
    QGridLayout *layoutRAM= new QGridLayout(ramGroup);
    layoutRAM->addWidget(label_clockRAM, 0, 0);
    layoutRAM->addWidget(textedit_clockRAM, 0, 1);
    ramGroup->setLayout(layoutRAM);


    for (int i = 0; i < 5; ++i) {
        layoutProcessor->setColumnStretch(i, 1);
        layoutRAM->setColumnStretch(i, 1);
    }
    mainLayout->addWidget(operatingSystemGroup);
    mainLayout->addWidget(processorGroup);
    mainLayout->addWidget(ramGroup);
    setLayout(mainLayout);
    getInforOperationSystem();
    getInforCPU();
    getClockRAM();
}
void Information :: getInforOperationSystem(){
    QFile file("/etc/issue");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"getInforOperationSystem can't open file!";
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    QRegularExpressionMatch match = myRegex.match(line);
    QString name = match.captured(1);
    QString version = match.captured(2);
    version.remove("\\n");
    version.remove("\\l");

    textedit_nameOperatingSystem->setText(name);
    textedit_versionOperatingSystem->setText(version);
    return;
}
void Information :: getInforCPU(){
    QFile file("/proc/cpuinfo");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"getInforCPU can't open file!";
        return;
    }
    QTextStream in(&file);
    QString line;
    do{
        line = in.readLine();
        if(line.contains("model name")){
            line = line.split(':').last();
            textedit_nameCPU->setText(line);
        }else if(line.contains("siblings")){
            line = line.split(':').last();
            textedit_threadCPU->setText(line);
        }else if(line.contains("cpu cores")){
            line = line.split(':').last();
            textedit_coreCPU->setText(line);
            break;
        }
    }while(in.atEnd()==false);
    return;
}
void Information::getClockRAM() {
    QProcess process;
    QStringList arguments;
    QString speeds;
    arguments << "-S" << "dmidecode" << "--type" << "memory";

    process.start("sudo", arguments);
    if (process.waitForStarted()) {
        process.write((PASSWORD + "\n").toLocal8Bit());
        process.closeWriteChannel();

        if (process.waitForFinished()) {
            QString output = process.readAllStandardOutput();
            QStringList lines = output.split('\n');
            for (const QString &line : lines) {
                if (line.contains("Configured Memory Speed:")) {
                    speeds = line.split(':').last().trimmed().split(' ').first()+" MHz";
                    break;
                }
            }
        }
    }
    textedit_clockRAM->setText(speeds);
}
