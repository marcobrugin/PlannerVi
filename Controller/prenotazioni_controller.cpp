#include "prenotazioni_controller.h"

PrenController::PrenController(storage* s, prenotazioni_view * p, Controller* c) : Controller(s, p, c){
    //collegamento segnale di aggiunta allo slot di aggiunta
    connect(view,SIGNAL(aggiugi_signal(aula, data, oraArrivo, oraUscita, causale, mail)),this,SLOT(aggiungi_enter(aula, data, oraArrivo, oraUscita, causale, mail)));
    view->setTitolo("SCHEDA PRENOTAZIONI");
    getView()->create_table({"Numero Aula","Data","Ora Arrivo", "Ora Uscita", "Causale", "Email utente"});
    getView()->carica_pren(s->getContPren());
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

void PrenController::aggiungi_enter(const int& aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail) const {
    string _causale=causale.toStdString();
    string _mail=mail.toStdString();
    utente* ut;
    aula* au;
    for(auto i : getModel()->getContPren()){
        if(i->getAula()->getNumero() == aula && i->getData()==data ){
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

void PrenController::indietro_enter() const {
    if(view->parent()){
        static_cast<View*>(view->parent())->show(); //è corretto?
        hide();
        delete this;
    }
}
