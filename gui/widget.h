#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

#include "core/encryptor.h"
#include "core/decryptor.h"

class Widget : public QWidget{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    //declaring main layout
    QGridLayout *mainLayout;
    //declaring encryptor and decryptor
    Encryptor encrypt;
    Decryptor decrypt;
    //declaring text edits
    QTextEdit *leftEdit;
    QTextEdit *rightEdit;
    //declaring button to modify text
    QPushButton *modify;
    //declaring combobox
    QComboBox *mode;
    //declaring line edit
    QLineEdit *keyEdit;
public slots:
    void modifyText();
};
#endif // WIDGET_H
