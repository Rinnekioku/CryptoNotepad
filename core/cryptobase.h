#ifndef CRYPTOBASE_H
#define CRYPTOBASE_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QPair>

class CryptoBase{
public:
    //declaring constructor for base class
    explicit CryptoBase(QString text = "", QString key = "");
    //declaring key getter
    QString getKey() const;
    //declaring setter for key
    void setKey(QString key);
    //declaring text getter
    QString getText() const;
    //declaring text setter
    void setText(QString text);
protected:
    //declaring key and text variables
    QString key_;
    QString text_;
    //declaring array of symbols
    QVector<QChar> symbols;
    //declaring function to form map of key and text
    QMap<int, QPair<int, int> > formCompareMap(QVector<int> first, QVector<int> second);
    //declraing function to create array of ASCII indicies of any word
    QVector<int> formIndicies(QString word);
};

#endif // CRYPTOBASE_H
