#ifndef THREAD_H
#define THREAD_H
#include <QApplication>
#include <QWidget>
#include <QThread>
#include <QTextEdit>
#include <QDebug>

class Thread: public QThread{
    Q_OBJECT
    public:
        Thread(QObject *parent = nullptr);
    signals:
        void temperatureCPUUpdated(double temperature);
        void perUsageCPUUpdated(double usagecpu);
        void perUsageRAMUpdated(double usageram );
        void clockCPUUpdated(double clockcpu);
    private:
        void run() override;
        double getTemperatureCPU();
        double getPerUsageCPU();
        double getPerUsageRAM();
        double getClockCPU();
};

#endif // THREAD_H
