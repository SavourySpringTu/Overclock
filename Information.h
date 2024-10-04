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
        void getClockRAM();
    private:
        QLabel *label_nameCPU;
        QLabel *label_packageCPU;
        QLabel *label_tdpCPU;
        QLabel *label_coreCPU;
        QLabel *label_threadCPU;
        QLabel *label_clockRAM;
        QTextEdit *textedit_clockRAM;
        QTextEdit *textedit_nameCPU;
        QGroupBox *processorGroup;
        QGroupBox *ramGroup;
};

#endif // INFOMATION_H
