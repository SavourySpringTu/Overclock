#include "Window.h"
#include "Thread.h"
#include <QTextEdit>

Window::Window(QWidget *parent) : QWidget(parent) {
    QWidget window;
    setFixedSize(650, 300);

    button_exit = new QPushButton("EXIT");
    button_exit->setFixedHeight(25);
    button_exit->setFixedWidth(150);

    label_temp = new QLabel(this);
    label_temp->setText("Temp CPU");
    label_use = new QLabel(this);
    label_use->setText("CPU Usage");

    textedit_temp = new QTextEdit(this);
    textedit_temp->setFixedHeight(25);
    textedit_temp->setFixedWidth(100);
    textedit_temp->setReadOnly(true);

    textedit_use = new QTextEdit(this);
    textedit_use->setFixedHeight(25);
    textedit_use->setFixedWidth(100);
    textedit_use->setReadOnly(true);

    layout = new QGridLayout(this);
    layout->addWidget(button_exit,0,5);
    layout->addWidget(label_temp,1,0);
    layout->addWidget(textedit_temp,1,1);
    layout->addWidget(label_use,2,0);
    layout->addWidget(textedit_use,2,1);

    Thread *thread = new Thread(this);
    connect(thread, &Thread::temperatureUpdated, this, &Window::updateTemperature);
    connect(thread, &Thread::usagecpuUpdated, this, &Window::updateUsagecpu);
    thread->start();

    connect(button_exit, &QPushButton::clicked, [thread]() {
        if (thread) {
            thread->requestInterruption();
            thread->quit();
            thread->wait();
        }
        QApplication::quit();
    });
}
void Window::updateTemperature(double temperature) {
    int roundedTemperature = qRound(temperature / 1000);
    QString temperatureString = QString("%1°C").arg(roundedTemperature);
    textedit_temp->setText(temperatureString);
}
void Window::updateUsagecpu(double usagecpu) {
    double roundedUsagecpu = qRound(usagecpu);
    QString usagecpuString = QString("%1%").arg(roundedUsagecpu);
    textedit_use->setText(usagecpuString);
}
