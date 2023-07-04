#include "salvataggio_dati.h"

QString salvataggio_dati::Json_File_Select(){
    QFileDialog window(nullptr);
    window.setFileMode(QFileDialog::ExistingFile);
    window.setNameFilter("JSON File (*.json)");
    QString name;
    if (window.exec())
        name = window.selectedFiles().at(0);
    return name;
}

QJsonDocument* salvataggio_dati::getFileJson(const QString& path){
    QString data;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    data = file.readAll();
    file.close();
    //analizzo se il file può essere considerato valido e utilizzabile
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(data.toLocal8Bit()));
    QJsonObject dataObj = doc->object();
    if(!dataObj.contains("data") && !dataObj.contains("autori") && !dataObj.contains("generi")){
        delete doc;
        return new QJsonDocument();
    }
    return doc;
}

bool salvataggio_dati::Save_Model(const QJsonDocument& doc,const QString& path){
    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        file.write(doc.toJson());
        file.close();
        return true;
    }
    return false;
}
