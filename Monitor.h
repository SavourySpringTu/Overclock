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
#include <QComboBox>
#include "Thread.h"

class Monitor:public QWidget{
    Q_OBJECT
    public:
        Monitor(QWidget *parent= nullptr);
        void createTabWidget();
    public slots:
        void updateTemperatureCPU(double temperature);
        void updatePerUsageCPU(double usagecpu);
        void updatePerUsageRAMandUsageRAM(vector<double> usageram);
        void updateCoreClockCPU(double clockcpu);
        void eventChangeOperationMode(int index);
        Thread * getThread() const;
    private:
        QTextEdit *textedit_temperatureCPU;
        QTextEdit *textedit_perUsageCPU;
        QTextEdit *textedit_usageRAM;
        QTextEdit *textedit_perUsageRAM;
        QTextEdit *textedit_coreClockCPU;

        QLabel *label_temperatureCPU;
        QLabel *label_perUsageCPU;
        QLabel *label_usageRAM;
        QLabel *label_perUsageRAM;
        QLabel *label_coreClockCPU;
        QLabel *label_operationMode;

        QComboBox *combobox_operationMode;

        QPushButton *run;
        Thread *thread;
        QGroupBox *processorGroup;
        QGroupBox *ramGroup;
        QGroupBox *overclockGroup;
        // function
        void getScalingAvailabel();
        void getOperationMode();
};

#endif // UI_MONITOR_H
