#ifndef INFOMATION_H
#define INFOMATION_H
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>

class Information:public QWidget{
    Q_OBJECT
    public:
        Information(QWidget *parent =nullptr);
        void getNameCPU();
    private:
        QLabel *label_nameCPU;
        QLabel *label_packageCPU;
        QLabel *label_tdpCPU;
        QLabel *label_coreCPU;
        QLabel *label_threadCPU;
        QTextEdit *textedit_cpuName;
        QGroupBox *processorGroup;
        QGroupBox *ramGroup;
};

#endif // INFOMATION_H
