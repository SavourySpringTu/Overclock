#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QTabWidget>
#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>
#include "Monitor.h"

class Window: public QWidget{
    Q_OBJECT

    public:
        Window(QWidget *parent = nullptr);
        void createTabWidget();
    protected:
        void closeEvent(QCloseEvent *event) override;
    private:
        QTabWidget *tabWidget;
        Monitor *monitorTab;
        QWidget *informationTab;
        QWidget *aboutTab;
        QWidget *authenticationTab;
};

#endif // WINDOW_H
