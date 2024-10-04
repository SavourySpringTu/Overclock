#include "Window.h"
#include "Monitor.h"
#include "Information.h"
#include "Thread.h"
#include "Global.h"
#include "About.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <QProcess>
#include <cstdio>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 600);
    //authentication(parent);
    PASSWORD = "Tu0562129598";
    setWindowTitle("Overclock");
    setWindowIcon(QIcon("/home/savouryspringtu/Tu/Projects/Overclock/resources/microchip.svg"));

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
    tabWidget->addTab(monitorTab, "Monitor");
    tabWidget->addTab(informationTab, "Infomation");
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
void Window::authentication(QWidget *parent) {
    bool ok;
    QString password = QInputDialog::getText(parent, "ROOT", "Password:", QLineEdit::Password, "", &ok);
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
    QProcess process;
    QString command = "sudo -S true";
    process.start(command);
    process.write(password.toUtf8()+ "\n");
    if(!process.waitForFinished(3000)==false){
        qDebug()<<"Error Process";
        process.close();
        return false;
    }
    int status = process.exitCode();
    return status;
}
