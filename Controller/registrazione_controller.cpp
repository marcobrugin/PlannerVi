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
/*
void RegController::Registr_enter(string _nome, string _cogn ) const {
    utente* nu= new utente (_nome, _cogn);
    for (int var = 0; var < total; ++var) {
        if()//controllo sulla mail
    };


    getModel()->addUtente(nu);
    //CLICCANDO SU REGISTRA deve inserire gli argomenti passati nel vettore<utenti> pers in storage
    // + controllare che la mail non sia già presente (utente già esistente)

    // e aprire la scheda di login
    login_view* logW =new login_view(QSize(300,400), view);
    logW->show();
    hide();
}*/

void RegController::onViewClosed() const {
    delete this;
}
