#include "Window.h"
#include "ThreadTempCPU.h"
#include <QTextEdit>

Window::Window(QWidget *parent) : QWidget(parent) {
    QWidget window;
    setFixedSize(650, 600);

    button_exit = new QPushButton("EXIT");
    button_exit->setFixedHeight(25);
    button_exit->setFixedWidth(150);

    run = new QPushButton("RUN");
    run->setFixedHeight(25);
    run->setFixedWidth(150);

    label_temp = new QLabel(this);
    label_temp->setText("Temp CPU");

    textedit_temp = new QTextEdit(this);
    textedit_temp->setFixedHeight(25);
    textedit_temp->setFixedWidth(150);
    textedit_temp->setReadOnly(true);


    layout = new QGridLayout(this);
    layout->addWidget(button_exit,0,5);
    layout->addWidget(label_temp,1,0);
    layout->addWidget(textedit_temp,1,1);
    layout->addWidget(run,1,2);


    ThreadTempCPU *thread = new ThreadTempCPU(this);
    connect(thread, &ThreadTempCPU::temperatureUpdated, this, &Window::updateTemperature);
    thread->start();
}
void Window::updateTemperature(double temperature) {
    int roundedTemperature = qRound(temperature / 1000);
    QString temperatureString = QString("%1°C").arg(roundedTemperature);
    textedit_temp->setText(temperatureString);
}
