#include "encryptor.h"
#include <QDebug>

Encryptor::Encryptor(QString text, QString key) : CryptoBase(text, key){

}

QString Encryptor::encrypt(){
    QVector<int> textIndicies = formIndicies(text_);
    QVector<int> keyIndicies = formIndicies(key_);
    QMap<int, QPair<int, int> > encryptMap = formCompareMap(textIndicies, keyIndicies);
    QString result;
    for (int i = 0; i < encryptMap.size(); i++){
        int index = (encryptMap[i].first+encryptMap[i].second)%symbols.size();
        result.append(symbols[index]);
    }

    return result;
}

