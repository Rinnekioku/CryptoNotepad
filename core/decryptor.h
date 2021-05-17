#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include <QChar>
#include <QVector>
#include <QDebug>

#include "cryptobase.h"

class Decryptor : public CryptoBase
{
public:
    //declaring decryptor constructor
    explicit Decryptor(QString text = "", QString key = "");
    //declaring decrypt function
    QString decrypt();
};

#endif // DECRYPTOR_H
