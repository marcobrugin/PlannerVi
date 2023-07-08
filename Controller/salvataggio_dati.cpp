#include "salvataggio_dati.h"

QString salvataggio_dati::JsonSelect(){
    QFileDialog window(nullptr);
    window.setFileMode(QFileDialog::ExistingFile);
    window.setNameFilter("JSON File (*.json)");
    QString name;
    if (window.exec())
        name = window.selectedFiles().at(0);
    return name;
}

QJsonDocument* salvataggio_dati::getFileJson(const QString& path){
    QString dati;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    dati = file.readAll();
    file.close();

    QJsonDocument* document = new QJsonDocument(QJsonDocument::fromJson(dati.toLocal8Bit()));
    QJsonObject datiObj = document->object();
    if(!datiObj.contains("prenotazioni") && !datiObj.contains("utenti")){
        delete document;
        return new QJsonDocument();
    }
    return document;
}

bool salvataggio_dati::SalvaModel(const QJsonDocument& document,const QString& path){
    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        file.write(document.toJson());
        file.close();
        return true;
    }
    return false;
}
