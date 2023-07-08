#include "menu_controller.h"
#include <QDebug>

MenuController::MenuController(storage* s, menu_view * m, Controller* c) : Controller(s, m, c){
    view->setTitolo("MENU");
    connect(view,SIGNAL(View_profilo_signal(const QString&)),this,SLOT(Profilo_enter(const QString&)));
    connect(view,SIGNAL(View_my_signal(const QString&)),this,SLOT(MyPren_enter(const QString&)));
    connect(view,SIGNAL(View_tutte_signal(const QString&)),this,SLOT(Pren_enter(const QString&)));
}

void MenuController::AulaView() const {}

storage* MenuController::getModel() const{
    return static_cast<storage*>(mod);
}
menu_view* MenuController::getView() const {
    return static_cast<menu_view*>(view) ;
}

void MenuController::Profilo_enter(const QString& mail) const {
    //estrapolare dalla mail l'utente
    utente* persona=nullptr;
    for(auto i: getModel()->getUtente()){
        if(i->getEmail()==(mail).toStdString()){
            persona=i;
        }
    }
    profilo_view* newW = new profilo_view(QSize(300,400), persona, view);
    ProfiloController* pC = new ProfiloController(getModel(), newW, const_cast<MenuController*>(this));
    pC->show();
    hide();
}

void MenuController::MyPren_enter(const QString& mail) const {
    myPren_view* myW = new myPren_view(QSize(900,400), mail, view);
    MyPrenController* myC = new MyPrenController (getModel(), myW, const_cast<MenuController*>(this));
    myC->show();
    hide();
}

void MenuController::Pren_enter(const QString& mail) const {
    prenotazioni_view* prW =new prenotazioni_view(QSize(900,400), mail, view);
    PrenController* prC= new PrenController(getModel(), prW, const_cast<MenuController*>(this));
    prC->show();
    hide();
}

void MenuController::onViewClosed() const {
    delete this;
}

void MenuController::salvataggio() const {
    if(!getModel()->getContPren().size() && !getModel()->getUtente().size()){
        view->showError("Errore", "Model vuoto");
    }
    QJsonDocument* document = new QJsonDocument();
    QJsonObject cartella;
    //QJsonArray archivio_aule;
    QJsonArray archivio_pren;
    QJsonArray archivio_ut;

    /*for(auto i: getModel()->getContAula()){
        QJsonObject record;
        record.insert(QString::fromStdString("Piano"),i->getPiano());
        record.insert(QString::fromStdString("Numero"),i->getNumero());
        record.insert(QString::fromStdString("Sede"),QString::fromStdString(i->getSede()));
        record.insert(QString::fromStdString("MaxPersone"),i->getMaxPersone());
        archivio_aule.push_back(record);
    }
*/
    for(auto i: getModel()->getContPren()){
        QJsonObject record1;
        record1.insert(QString::fromStdString("Persona"),QString::fromStdString(i->getPersona()));
        record1.insert(QString::fromStdString("Data"),i->getData().toString());
        record1.insert(QString::fromStdString("OraArrivo"),i->getOraArrivo().toString());
        record1.insert(QString::fromStdString("OraUscita"),i->getOraUscita().toString());
        record1.insert(QString::fromStdString("Causale"),QString::fromStdString(i->getCausale()));
        record1.insert(QString::fromStdString("Aula"),i->getAula());
        archivio_pren.push_back(record1);
    }
    for(auto i: getModel()->getUtente()){
        QJsonObject record2;
        record2.insert(QString::fromStdString("Nome"),QString::fromStdString(i->getNome()));
        record2.insert(QString::fromStdString("Cognome"),QString::fromStdString(i->getCognome()));
        record2.insert(QString::fromStdString("CodFiscale"),QString::fromStdString(i->getCodiceFiscale()));
        record2.insert(QString::fromStdString("Telefono"),QString::fromStdString(i->getTelefono()));
        record2.insert(QString::fromStdString("Email"),QString::fromStdString(i->getEmail()));
        record2.insert(QString::fromStdString("Password"),QString::fromStdString(i->getPassword()));
        archivio_ut.push_back(record2);
    }
    //cartella.insert(QString::fromStdString("aule"),archivio_aule);
    cartella.insert(QString::fromStdString("prenotazioni"),archivio_pren);
    cartella.insert(QString::fromStdString("utenti"),archivio_ut);

    document->setObject(cartella);

    QString nome = QFileDialog::getSaveFileName(view,QObject::tr("Salva con nome"),nullptr,"JSON Files (*.json)");
    if(nome.isEmpty() || nome.isNull()){
        view->showError(QObject::tr("Errore Salvataggio"),QObject::tr("Salvataggio fallito"));
        return;
    }
    if (!nome.endsWith(".json"))
        nome+= QObject::tr(".json");

    if(salvataggio_dati::SalvaModel(*document,nome))
        view->showMessage(QObject::tr("Salvataggio"),QObject::tr("Salvataggio riuscito"));
    else
        view->showError(QObject::tr("Errore di salvataggio"),QObject::tr("Salvataggio non riuscito"));
    delete document;

}
