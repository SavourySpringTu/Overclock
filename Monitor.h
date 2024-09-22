#ifndef MONITOR_H
#define MONITOR_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include <QTabWidget>
#include "Thread.h"

class Monitor:public QWidget{
    Q_OBJECT
    public:
        Monitor(QWidget *parent= nullptr);
        ~Monitor();
        void createTabWidget();
    public slots:
        void updateTemperature(double temperature);
        void updateUsagecpu(double usagecpu);
        Thread * getThread() const;
    private:
        QTextEdit *textedit_temp;
        QTextEdit *textedit_use;
        QLabel *label_temp;
        QLabel *label_use;
        QPushButton *run;
        Thread *thread;
        QGridLayout *layout;
};

#endif // MONITOR_H
