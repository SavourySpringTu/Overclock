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
        void getInforCPU();
        void getClockRAM();
        void getInforOperationSystem();
    private:
        QLabel *label_nameCPU;
        QLabel *label_packageCPU;
        QLabel *label_tdpCPU;
        QLabel *label_coreCPU;
        QLabel *label_threadCPU;
        QLabel *label_clockRAM;
        QLabel *label_nameOperatingSystem;
        QLabel *label_versionOperatingSystem;

        QTextEdit *textedit_clockRAM;
        QTextEdit *textedit_nameCPU;
        QTextEdit *textedit_coreCPU;
        QTextEdit *textedit_threadCPU;
         QTextEdit *textedit_nameOperatingSystem;
        QTextEdit *textedit_versionOperatingSystem;

        QGroupBox *processorGroup;
        QGroupBox *ramGroup;
        QGroupBox *operatingSystemGroup;
};

#endif // INFOMATION_H
