#include "Window.h"
#include "Monitor.h"
#include "Information.h"
#include "Authentication.h"
#include "Thread.h"
#include "About.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <QProcess>
#include <cstdio>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 600);
    setWindowTitle("Overclock");
    setWindowIcon(QIcon(":/resources/microchip-solid.svg"));

    // Create tab widget
    tabWidget = new QTabWidget(this);
    createTabWidget();

    //Set layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
}

void Window::createTabWidget(){
    monitorTab = new Monitor();
    informationTab = new Information();
    aboutTab = new About();
    authenticationTab = new Authentication();
    tabWidget->addTab(monitorTab, "Monitor");
    tabWidget->addTab(informationTab, "Infomation");
    tabWidget->addTab(authenticationTab,"Authentication");
    tabWidget->addTab(aboutTab, "About");
}
void Window::closeEvent(QCloseEvent *event) { {
    Thread *thread = monitorTab->getThread();
        if (thread) {
            thread->requestInterruption();
            thread->quit();
            thread->wait();
        }
    }
    QApplication::quit();
}
