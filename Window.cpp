#include "Window.h"
#include "Monitor.h"
#include "Information.h"
#include "Thread.h"
#include "Global.h"
#include "About.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <cstdio>

Window::Window(QWidget *parent) : QWidget(parent) {
    //authentication(parent);
    PASSWORD = "Tu0562129598";
    setWindowTitle("Overclock");
    setWindowIcon(QIcon(":/microchip-solid.svg"));
    setFixedSize(650, 600);

    tabWidget = new QTabWidget(this);
    createTabWidget();
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
    informationTab = new Information();
    aboutTab = new About();
    tabWidget->addTab(monitorTab, "Monitor");
    tabWidget->addTab(informationTab, "Infomation");
    tabWidget->addTab(aboutTab, "About");
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
void Window::authentication(QWidget *parent) {
    bool ok;
    QString password = QInputDialog::getText(parent, "Authentication", "Enter password:", QLineEdit::Password, "", &ok);
    if (!ok) {
        std::exit(EXIT_SUCCESS);
    } else {
        if (checkPassword(password)) {
            PASSWORD = password;
        } else {
            authentication(parent);
        }
    }
}

bool Window::checkPassword(const QString &password) {
    QString command = "echo " + password + " | sudo -S true";
    FILE *pipe = popen(command.toUtf8().constData(), "r");
    int status = pclose(pipe);
    return (status == 0);
}
