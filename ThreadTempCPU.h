#ifndef THREADTEMPCPU_H
#define THREADTEMPCPU_H
#include <QApplication>
#include <QWidget>
#include <QThread>
#include <QTextEdit>
#include <QDebug>

class ThreadTempCPU: public QThread{
    Q_OBJECT
    public:
        ThreadTempCPU(QObject *parent = nullptr);
    signals:
        void temperatureUpdated(double temperature);
    private:
        void run() override;
        double getTemperature();
};

#endif // THREADTEMPCPU_H
