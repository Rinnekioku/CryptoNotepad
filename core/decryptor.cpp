#include "decryptor.h"

Decryptor::Decryptor(QString text, QString key) : CryptoBase(text, key){

}

QString Decryptor::decrypt(){
    QVector<int> textIndicies = formIndicies(text_);
    QVector<int> keyIndicies = formIndicies(key_);
    QMap<int, QPair<int, int> > decryptMap = formCompareMap(textIndicies, keyIndicies);
    QString result;
    for (int i = 0; i < decryptMap.size(); i++){
        int index = (decryptMap[i].first-decryptMap[i].second+symbols.size())%symbols.size();
        result.append(symbols[index]);
    }

    return result;
}
