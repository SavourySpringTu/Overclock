#include "Monitor.h"
#include "Thread.h"

Monitor::Monitor(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 300);  // Đặt kích thước cho Monitor

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
    layout->addWidget(label_temp, 1, 0);
    layout->addWidget(textedit_temp, 1, 1);
    layout->addWidget(label_use, 2, 0);
    layout->addWidget(textedit_use, 2, 1);

    Thread *thread = new Thread(this);
    connect(thread, &Thread::temperatureUpdated, this, &Monitor::updateTemperature);
    connect(thread, &Thread::usagecpuUpdated, this, &Monitor::updateUsagecpu);
    thread->start();
}

void Monitor::updateTemperature(double temperature) {
    int roundedTemperature = qRound(temperature / 1000);
    QString temperatureString = QString("%1°C").arg(roundedTemperature);
    textedit_temp->setText(temperatureString);
}

void Monitor::updateUsagecpu(double usagecpu) {
    double roundedUsagecpu = qRound(usagecpu);
    QString usagecpuString = QString("%1%").arg(roundedUsagecpu);
    textedit_use->setText(usagecpuString);
}
Thread* Monitor::getThread() const {
    if (thread) {  // Kiểm tra nếu thread hợp lệ
        return thread;
    }
    return nullptr;
}
Monitor::~Monitor() {
    if (thread) {
        thread->requestInterruption();  // Dừng luồng khi widget bị phá hủy
        thread->quit();
        thread->wait();  // Đảm bảo luồng dừng hoàn toàn trước khi giải phóng
    }
}
