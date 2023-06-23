#include "admin_controller.h"

AdminController::AdminController(){}

AdminController::AdminController(storage* s, admin_view * a, Controller* c) : Controller(s, a, c){
    view->setTitolo("VISUALIZZAZIONE ADMIN");
    getView()->create_table({"Numero Aula","Data","Ora Arrivo", "Ora Uscita", "Causale", "Email utente"});
    getView()->visualizza_prenotazioni(s->getContPren());
    connect(view,SIGNAL(rimuovi_signal(i)),this,SLOT(rimuovi_enter(i)));
    connect(view,SIGNAL(aggiugi_signal(aula, data, oraArrivo, oraUscita, causale, mail)),this,SLOT(aggiungi_enter(aula, data, oraArrivo, oraUscita, causale, mail)));
}
storage* AdminController::getModel()const {
    return static_cast<storage*>(mod);
}

admin_view* AdminController::getView() const{
    return static_cast<admin_view*>(view) ;
}

void AdminController::aggiungi_enter(const int& aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail) const {
    string _causale=causale.toStdString();
    string _mail=mail.toStdString();
    utente* ut;
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
    }
    //mettere in ordine ed estrapolare l'utente* dalla mail
    prenotazione* nuova = new prenotazione(aula,data,oraArrivo,oraUscita,causale.toStdString(),ut);//con le conversioni adeguate!
    getModel()->addPrenotazione(nuova);
    getView()->addToView(nuova);
}

void AdminController::rimuovi_enter(uint i){
    getModel()->removePrenotazione(i);
}

void AdminController::onViewClosed() const {
    delete this;
}
