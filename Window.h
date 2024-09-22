#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QTabWidget>
#include <QWidget>
#include <QPushButton>

class Window: public QWidget{
    Q_OBJECT

    public:
        Window(QWidget *parent = nullptr);
        void createTabWidget();
        void setupExitButton();
    private:
        QPushButton *button_exit;
        QTabWidget *tabWidget;
        QWidget *monitorTab;
        QWidget *informationTab;
};

#endif // WINDOW_H
