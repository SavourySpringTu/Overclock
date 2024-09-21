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
        void temperatureUpdated(double temperature);
        void usagecpuUpdated(double usagecpu);
    private:
        void run() override;
        double getTemperature();
        double getUsagecpu();
};

#endif // THREAD_H
