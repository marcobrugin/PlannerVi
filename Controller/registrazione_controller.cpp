#include "registrazione_controller.h"

RegController::RegController(storage* s, registrazione_view * r, Controller* c) : Controller(s, r, c){
    connect(view,SIGNAL(Reg_signal(em, pass)),this,SLOT(Registr_enter(_nome, _cognome)));
}
storage* RegController::getModel()const {
    return static_cast<storage*>(mod);
}
registrazione_view* RegController::getView() const{
    return static_cast<registrazione_view*>(view) ;
}

void RegController::Registr_enter(const QString& _nome, const QString& _cogn, const QString& _cod, const QString& _ph, const QString& _mail, const QString& _pass ) const {
    for (auto it : getModel()->getUtente()) {
        //controllo sulla mail
        if(it->getEmail()== (_mail).toStdString()){
            view->showError("Errore", "Utente già esistente");
            return;
        }
    }
    utente* nu= new utente(_nome.toStdString(), _cogn.toStdString(), _cod.toStdString(), _ph.toStdString(), _mail.toStdString(), _pass.toStdString());
    getModel()->addUtente(nu);

    // e tornare alla scheda di login
    if(view->parent()){
        static_cast<View*>(view->parent())->show();
        hide();
        delete this;
    }
}

void RegController::onViewClosed() const {
    delete this;
}
