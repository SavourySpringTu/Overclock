#include "Information.h"
#include "Global.h"
#include <QVBoxLayout>
#include <QProcess>
#include <QFile>

Information::Information(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 300);
    label_nameCPU = new QLabel("Name", this);
    label_nameCPU->setAlignment(Qt::AlignLeft);
    label_nameCPU->setFixedHeight(25);
    label_nameCPU->setFixedWidth(50);

    label_clockRAM = new QLabel("Bus", this);
    label_clockRAM->setAlignment(Qt::AlignLeft);
    label_clockRAM->setFixedHeight(25);
    label_clockRAM->setFixedWidth(50);

    textedit_nameCPU = new QTextEdit(this);
    textedit_nameCPU->setFixedHeight(25);
    textedit_nameCPU->setFixedWidth(350);
    textedit_nameCPU->setReadOnly(true);
    textedit_nameCPU->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    textedit_clockRAM = new QTextEdit(this);
    textedit_clockRAM->setFixedHeight(25);
    textedit_clockRAM->setFixedWidth(100);
    textedit_clockRAM->setReadOnly(true);
    textedit_clockRAM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    processorGroup = new QGroupBox("Processor", this);
    QGridLayout *layoutProcessor = new QGridLayout(processorGroup);
    layoutProcessor->addWidget(label_nameCPU, 0, 0);
    layoutProcessor->addWidget(textedit_nameCPU, 0, 1);
    processorGroup->setLayout(layoutProcessor);

    ramGroup = new QGroupBox("RAM",this);
    QGridLayout *layoutRAM= new QGridLayout(ramGroup);
    layoutRAM->addWidget(label_clockRAM, 0, 0);
    layoutRAM->addWidget(textedit_clockRAM, 0, 1);
    //layoutProcessor->setAlignment(textedit_clockRAM, Qt::AlignLeft);
    ramGroup->setLayout(layoutRAM);


    for (int i = 0; i < 5; ++i) {
        layoutProcessor->setColumnStretch(i, 1);
        layoutRAM->setColumnStretch(i, 1);
    }
    mainLayout->addWidget(processorGroup);
    mainLayout->addWidget(ramGroup);
    setLayout(mainLayout);
    getNameCPU();
    getClockRAM();
}
void Information :: getNameCPU(){
    QFile file("/proc/cpuinfo");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Can't open file!";
        return;
    }
    QTextStream in(&file);
    QString line;
    do{
        line = in.readLine();
        if(line.contains("model name")){
            break;
        }
    }while(in.atEnd()==false);
    line = line.split(':').last();
    textedit_nameCPU->setText(line);
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
