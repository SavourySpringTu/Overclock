#ifndef THREAD_H
#define THREAD_H
#include <QApplication>
#include <QWidget>
#include <QThread>
#include <QTextEdit>
#include <QDebug>
#include <vector>
using namespace std;

class Thread: public QThread{
    Q_OBJECT
    public:
        Thread(QObject *parent = nullptr);
    signals:
        void temperatureCPUUpdated(double temperature);
        void perUsageCPUUpdated(double usagecpu);
        void usageRAMUpdated(vector<double> usageram );
        void coreClockCPUUpdated(double clockcpu);
        void powerConsumptionUpdated(double usagepower);
    private:
        void run() override;
        double getTemperatureCPU();
        double getPerUsageCPU();
        vector<double> getUsageRAM();
        double getCoreClockCPU();
        double readUsageCPU();
        double getConsumptionPower();
};

#endif // THREAD_H
