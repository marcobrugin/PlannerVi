#include "prenotazioni_controller.h"

PrenController::PrenController(storage* s, prenotazioni_view * p, Controller* c) : Controller(s, p, c){
    //collegamento segnale di aggiunta allo slot di aggiunta
    connect(view,SIGNAL(aggiugi_signal(aula, data, oraArrivo, oraUscita, causale, mail)),this,SLOT(aggiungi_enter(aula, data, oraArrivo, oraUscita, causale, mail)));
    view->setTitolo("SCHEDA PRENOTAZIONI");
    getView()->create_table({"inserire i vari headers","ciao"});//DA FARE
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

void PrenController::aggiungi_enter(const QString& aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail) const {
    //getModel()->getContPren();
    for(auto i : getModel()->getContPren()){
        if(i->getAula()==aula || ){ //  CONVERTIRE e fare tutti i controlli
            view->showError("","");
            return;
        }
    }
    prenotazione* nuova = new prenotazione(aula,data);//con le conversioni adeguate!
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
