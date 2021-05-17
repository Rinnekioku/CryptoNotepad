#include "cryptobase.h"

#include <QDebug>

CryptoBase::CryptoBase(QString text, QString key){
    text_ = text;
    key_ = key;
    for (int i = 32; i < 127; i++){
        symbols.push_back(QChar(i));
    }
    QString russian = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < russian.size(); i++){
        symbols.push_back(russian[i]);
    }
}

QString CryptoBase::getKey() const{
    return key_;
}

void CryptoBase::setKey(QString key){
    key_ = key;
}

QString CryptoBase::getText() const{
    return text_;
}

void CryptoBase::setText(QString text){
    text_ = text;
}

QMap<int, QPair<int, int> > CryptoBase::formCompareMap(QVector<int> text, QVector<int> key){
    QMap<int, QPair<int, int> > result;
    for (int i = 0; i < text.size(); i++){
        result.insert(i, qMakePair(text[i], key[i%key.size()]));
    }

    return result;
}

QVector<int> CryptoBase::formIndicies(QString word){
    QVector<int> result;
    for(int i = 0; i < word.length(); i++){
        for(int j = 0; j < symbols.size(); j++){
            if (word[i] == symbols[j]) result.push_back(j);
        }
    }

    return result;
}
