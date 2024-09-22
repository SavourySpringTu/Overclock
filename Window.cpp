#include "Window.h"
#include "Monitor.h"
#include "Thread.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 600);

    setupExitButton();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *exitLayout = new QHBoxLayout();
    exitLayout->addStretch();
    exitLayout->addWidget(button_exit);
    mainLayout->addLayout(exitLayout);
    mainLayout->addWidget(tabWidget);

    setLayout(mainLayout);
}

void Window::createTabWidget(){
    Monitor *monitor = new Monitor();
    monitorTab = monitor;
    informationTab = new QWidget();
    QGridLayout *memoryLayout = new QGridLayout(informationTab);
    informationTab->setLayout(memoryLayout);
    tabWidget->addTab(monitorTab, "Monitor");
    tabWidget->addTab(informationTab, "Info");
}
void Window::setupExitButton() {
    button_exit = new QPushButton("EXIT", this);
    button_exit->setFixedSize(100, 30);

    if (monitorTab) {
        Monitor *monitor = dynamic_cast<Monitor *>(monitorTab);

        connect(button_exit, &QPushButton::clicked, [monitor]() {
            if (monitor) {
                Thread *thread = monitor->getThread();
                if (thread) {
                    thread->requestInterruption();
                    thread->quit();
                    thread->wait();
                }
            }
            QApplication::quit();
        });
    }
}

