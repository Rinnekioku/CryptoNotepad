#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <QChar>
#include <QVector>

#include "cryptobase.h"

class Encryptor : public CryptoBase
{
public:
    //declaring encryptor constructor
    explicit Encryptor(QString text = "", QString key = "");
    //declaring encrypt function
    QString encrypt();
};

#endif // ENCRYPTOR_H
