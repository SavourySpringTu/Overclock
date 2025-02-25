#include "Authentication.h"
#include <QFile>
#include <QDebug>

Authentication::Authentication (QWidget *parent) : QWidget(parent) {
    setFixedSize(650, 400);
    label_root = new QLabel("Root",this);
    label_root->setFixedWidth(75);
    label_root->setFixedHeight(25);

    textedit_password = new QTextEdit();
    textedit_password->setFixedHeight(25);
    textedit_password->setFixedWidth(100);

    button_save = new QPushButton("Save",this);
    button_save->setFixedHeight(25);
    button_save->setFixedWidth(100);

    QGridLayout *layoutPassword = new QGridLayout();
    layoutPassword->addWidget(label_root,0,0);
    layoutPassword->addWidget(textedit_password,1,0);
    layoutPassword->addWidget(button_save,2,0);

    setLayout(layoutPassword);
}
// void Authentication :: savePassword(QTextEdit *text_edit,const QString &filePath){
//     QFile file(filePath);
//     if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
//         qDebug()<<"Can't open file password!";
//         return;
//     }
//     QTextStream out(&file);
//     out << text_edit->toPlainText();
//     file.close();
// }
