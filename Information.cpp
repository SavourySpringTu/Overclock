#include "Information.h"
#include <QVBoxLayout>
#include <QProcess>
#include <QFile>

Information::Information(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 300);
    label_nameCPU = new QLabel("Name", this);
    label_nameCPU->setAlignment(Qt::AlignLeft);
    label_nameCPU->setFixedHeight(25);
    label_nameCPU->setFixedWidth(50);

    textedit_cpuName = new QTextEdit(this);
    textedit_cpuName->setFixedHeight(25);
    textedit_cpuName->setFixedWidth(350);
    textedit_cpuName->setReadOnly(true);
    textedit_cpuName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Khởi tạo mainLayout mà không truyền `this`
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    processorGroup = new QGroupBox("Processor", this);
    QGridLayout *layoutProcessor = new QGridLayout(processorGroup);
    layoutProcessor->addWidget(label_nameCPU, 0, 0);
    layoutProcessor->addWidget(textedit_cpuName, 0, 1);
    layoutProcessor->setAlignment(label_nameCPU, Qt::AlignLeft);
    processorGroup->setLayout(layoutProcessor);

    ramGroup = new QGroupBox("Ram", this);
    QGridLayout *layoutRAM = new QGridLayout(ramGroup);
    processorGroup->setLayout(layoutProcessor);

    for (int i = 0; i < 5; ++i) {
        layoutProcessor->setColumnStretch(i, 1);
        layoutRAM->setColumnStretch(i, 1);
    }
    mainLayout->addWidget(processorGroup);
    mainLayout->addWidget(ramGroup);
    setLayout(mainLayout);
    getNameCPU();
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
    textedit_cpuName->setText(line);
    return;
}
