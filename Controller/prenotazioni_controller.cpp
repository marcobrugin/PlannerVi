#include "prenotazioni_controller.h"

PrenController::PrenController(){}

PrenController::PrenController(storage* s, prenotazioni_view * p, Controller* c) : Controller(s, p, c){
    view->setTitolo("SCHEDA PRENOTAZIONI");
    getView()->create_table({"Numero Aula","Data","Ora Arrivo", "Ora Uscita", "Causale", "Email utente", "Aggiungi"});
    getView()->carica_pren(s->getContPren());
    connect(view,SIGNAL(aggiugi_signal(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&)),this,SLOT(aggiungi_enter(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&)));
    connect(view,SIGNAL(rimuovi_signal(uint)),this,SLOT(rimuovi_enter(uint)));
     connect(view,SIGNAL(indietro_signal()),this,SLOT(indietro_enter()));

}

storage* PrenController::getModel()const {
    return static_cast<storage*>(mod);
}

prenotazioni_view* PrenController::getView() const{
    return static_cast<prenotazioni_view*>(view) ;
}

void PrenController::onViewClosed() const {
    delete this;
}

void PrenController::aggiungi_enter(const int& _aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& email) const {
    string _causale=causale.toStdString();
    string _mail=email.toStdString();
    utente* ut;
    aula* au;
    for(auto i : getModel()->getContPren()){
        if(i->getAula()->getNumero() == _aula && i->getData()==data ){
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
    //mettere in ordine
    prenotazione* nuova = new prenotazione(ut,data,oraArrivo,oraUscita,causale.toStdString(),au);
    getModel()->addPrenotazione(nuova);
    getView()->addToView(nuova);
}

void PrenController::rimuovi_enter(uint i){
    getModel()->removePrenotazione(i);
}

void PrenController::indietro_enter() {
    static_cast<const MenuController*>(this->parent())->show();
    this->hide();
}
