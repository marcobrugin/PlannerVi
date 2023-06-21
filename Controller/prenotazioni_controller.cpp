#include "prenotazioni_controller.h"

PrenController::PrenController(storage* s, prenotazioni_view * p, Controller* c) : Controller(s, p, c){
    connect(view,SIGNAL(aggiugi_signal(aula, data, oraArrivo, oraUscita, causale, mail)),this,SLOT(aggiungi_enter(aula, data, oraArrivo, oraUscita, causale, mail)));
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
//deve aggiungere al file JSON la nuova prenotazione
}

void PrenController::indietro_enter() const {
    if(view->parent()){
        static_cast<View*>(view->parent())->show(); //è corretto?
        hide();
        delete this;
    }
}
