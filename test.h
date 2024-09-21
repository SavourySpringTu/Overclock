#ifndef TEST_H
#define TEST_H
#include <QApplication>
#include <QWidget>

class test: public QWidget{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
};
#endif // TEST_H
