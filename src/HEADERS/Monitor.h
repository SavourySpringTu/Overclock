#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include <QTabWidget>
#include <QGroupBox>
#include "Thread.h"

class Monitor:public QWidget{
    Q_OBJECT
    public:
        Monitor(QWidget *parent= nullptr);
        void createTabWidget();
        void getClockRAM();
    public slots:
        void updateTemperatureCPU(double temperature);
        void updateUsageCPU(double usagecpu);
        void updateUsageRAM(double usageram);
        void updateClockCPU(double clockcpu);
        Thread * getThread() const;
    private:
        QTextEdit *textedit_cpuTemp;
        QTextEdit *textedit_cpuUse;
        QTextEdit *textedit_ramClock;
        QTextEdit *textedit_ramUse;
        QTextEdit *textedit_cpuClock;

        QLabel *label_cpuTemp;
        QLabel *label_cpuUse;
        QLabel *label_ramClock;
        QLabel *label_ramUse;
        QLabel *label_cpuClock;

        QPushButton *run;
        Thread *thread;
        QGroupBox *processorGroup;
        QGroupBox *ramGroup;
};

#endif // UI_MONITOR_H
