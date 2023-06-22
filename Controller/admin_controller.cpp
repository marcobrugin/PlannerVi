#include "admin_controller.h"

AdminController::AdminController(){}

AdminController::AdminController(storage* s, admin_view * a, Controller* c) : Controller(s, a, c){
    connect(view,SIGNAL(rimuovi_signal(i)),this,SLOT(rimuovi_enter(i)));
    //connect(view,SIGNAL(Label_signal()),this,SLOT(Label_enter())); AGGIUNTA
}
storage* AdminController::getModel()const {
    return static_cast<storage*>(mod);
}

admin_view* AdminController::getView() const{
    return static_cast<admin_view*>(view) ;
}

void AdminController::rimuovi_enter(uint i){
    getModel()->removePrenotazione(i);
}

void AdminController::onViewClosed() const {
    delete this;
}
