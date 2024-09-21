#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include "Thread.h"

class Window: public QWidget{
    Q_OBJECT

    public:
        Window(QWidget *parent = nullptr);
    public slots:
        void updateTemperature(double temperature);
        void updateUsagecpu(double usagecpu);
    private:
        QTextEdit *textedit_temp;
        QTextEdit *textedit_use;
        QPushButton *button_exit;
        QLabel *label_temp;
        QLabel *label_use;
        QPushButton *run;
        Thread *thread;
        QGridLayout *layout;
};

#endif // WINDOW_H
