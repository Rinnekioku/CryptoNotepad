#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    //init main layout
    mainLayout = new QGridLayout;
    //init text edits
    leftEdit = new QTextEdit;
    leftEdit->setPlaceholderText("Type here text to decrypt or encrypt");
    rightEdit = new QTextEdit;
    rightEdit->setPlaceholderText("Here you will see the result of encryption or decryption");
    keyEdit = new QLineEdit;
    keyEdit->setPlaceholderText("Type your key here");
    //init buttons
    modify = new QPushButton;
    modify->setText("Modify");
    //init combobox
    mode = new QComboBox;
    mode->insertItem(0, "Encrypt");
    mode->insertItem(1, "Decrypt");
    //filling layout
    mainLayout->addWidget(leftEdit, 0, 0);
    mainLayout->addWidget(rightEdit, 0, 1);
    mainLayout->addWidget(keyEdit, 1, 0, 1, 2, Qt::AlignCenter);
    mainLayout->addWidget(mode, 2, 0);
    mainLayout->addWidget(modify, 2, 1);
    //setting layout
    setLayout(mainLayout);

    connect(modify, SIGNAL(clicked()), this, SLOT(modifyText()));
}

Widget::~Widget(){
    delete mainLayout;
    delete leftEdit;
    delete rightEdit;
    delete modify;
    delete mode;
    delete keyEdit;
}

void Widget::modifyText(){
    switch (mode->currentIndex()) {
        case 0:
            encrypt.setText(leftEdit->toPlainText());
            encrypt.setKey(keyEdit->text());
            rightEdit->setText(encrypt.encrypt());
            break;
        case 1:
            decrypt.setText(leftEdit->toPlainText());
            decrypt.setKey(keyEdit->text());
            rightEdit->setText(decrypt.decrypt());
            break;
    }
}
