#ifndef SALVATAGGIO_DATI_H
#define SALVATAGGIO_DATI_H

#include<QString>
#include<QJsonDocument>
#include<QFileDialog>
#include<QJsonObject>

class salvataggio_dati {

protected:
    //Costruttori protetti
    explicit salvataggio_dati();
    explicit salvataggio_dati(const salvataggio_dati&)=delete;

public:
    virtual ~salvataggio_dati()=default;
    static QString JsonSelect();
    static QJsonDocument* getFileJson(const QString&);
    static bool SalvaModel(const QJsonDocument&, const QString&);
};

#endif // SALVATAGGIO_DATI_H
