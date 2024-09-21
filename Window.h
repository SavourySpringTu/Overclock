#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include "ThreadTempCPU.h"

class Window: public QWidget{
    Q_OBJECT

    public:
        Window(QWidget *parent = nullptr);
    public slots:
        void updateTemperature(double temperature);
    private:
        QTextEdit *textedit_temp;
        QPushButton *button_exit;
        QLabel *label_temp;
        QPushButton *run;
        ThreadTempCPU *thread;
        QGridLayout *layout;
};

#endif // WINDOW_H
