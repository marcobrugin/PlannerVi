#include "registrazione_controller.h"

RegController::RegController(storage* s, registrazione_view * r, Controller* c) : Controller(s, r, c){
    connect(view,SIGNAL(Utente_add_signal(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&)),this,SLOT(Registr_enter(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&)));
}
storage* RegController::getModel()const {
    return static_cast<storage*>(mod);
}
registrazione_view* RegController::getView() const{
    return static_cast<registrazione_view*>(view) ;
}

void RegController::Registr_enter(const QString& _nome, const QString& _cogn, const QString& _cod, const QString& _ph, const QString& _mail, const QString& _ruolo, const QString& _pass ) const {
    for (auto it : getModel()->getUtente()) {
        //controllo sulla mail
        if(it->getEmail()== (_mail).toStdString()){
            view->showError("Errore", "Utente già esistente");
            return;
        }
    }
    utente* nu= new utente(_nome.toStdString(), _cogn.toStdString(), _cod.toStdString(), _ph.toStdString(), _mail.toStdString(), _ruolo.toStdString(), _pass.toStdString());
    getModel()->addUtente(nu);

    // e tornare alla scheda di login
    static_cast<const LoginController*>(this->parent())->show();
    this->hide();
}

void RegController::onViewClosed() const {
    delete this;
}
