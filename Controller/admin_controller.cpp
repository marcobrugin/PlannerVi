#include "admin_controller.h"

AdminController::AdminController(){}

AdminController::AdminController(storage* s, admin_view * a, Controller* c) : Controller(s, a, c){
    view->setTitolo("VISUALIZZAZIONE ADMIN");
    getView()->create_table({"Numero Aula","Data","Ora Arrivo", "Ora Uscita", "Causale", "Email utente","Rimuovi","Aggiungi"});
    getView()->visualizza_prenotazioni(s->getContPren());
    connect(view,SIGNAL(rimuovi_signal(uint)),this,SLOT(rimuovi_enter(uint)));
    connect(view,SIGNAL(elimina_signal(uint)),this,SLOT(rimuovi_enter(uint)));
    connect(view,SIGNAL(aggiugi_signal(const int, const QDate, const QTime, const QTime, const QString, const QString)),this,SLOT(aggiungi_enter(aula, data, oraArrivo, oraUscita, causale, mail)));
}
storage* AdminController::getModel()const {
    return static_cast<storage*>(mod);
}

admin_view* AdminController::getView() const{
    return static_cast<admin_view*>(view) ;
}

void AdminController::aggiungi_enter(const int& _aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail) const {
    string _causale=causale.toStdString();
    string _mail=mail.toStdString();
    string ut;
    int au;
    for(auto i : getModel()->getContPren()){
        if(i->getAula() == _aula && i->getData()==data ){
            QTime arrivo= i->getOraArrivo();
            QTime uscita= i->getOraUscita();
            if((oraArrivo>=arrivo && oraArrivo<uscita) || (oraUscita>arrivo && oraUscita<=uscita) || (oraArrivo<= arrivo && oraUscita>=uscita)){
                view->showError("Prenotazione errata","L'aula è già occupata nell'ora/data selezionata");
            }
            return;
        }
        ut=i->getPersona();
        au=i->getAula();
    }
    //mettere in ordine ed estrapolare l'utente* dalla mail
    prenotazione* nuova = new prenotazione(ut,data,oraArrivo,oraUscita,causale.toStdString(),au);
    getModel()->addPrenotazione(nuova);
    getView()->addToView(nuova);
}

void AdminController::rimuovi_enter(uint i){
    getModel()->removePrenotazione(i);
}

void AdminController::onViewClosed() const {
    delete this;
}
