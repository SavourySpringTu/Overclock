#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>

class Authentication : public QWidget {
    Q_OBJECT
public:
    Authentication(QWidget *parent = nullptr);
    void savePassword(QTextEdit *text_edit,const QString &filePath);
private:
    QLabel *label_root;
    QTextEdit *textedit_password;
    QPushButton *button_save;
};
#endif // AUTHENTICATION_H
