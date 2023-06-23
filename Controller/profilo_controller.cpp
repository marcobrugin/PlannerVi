#include "profilo_controller.h"

ProfiloController::ProfiloController(){}

ProfiloController::ProfiloController(storage* s, profilo_view * p, Controller* c) : Controller(s, p, c){
    connect(view,SIGNAL(indietro_signal()),this,SLOT(indietro_enter()));
}

storage* ProfiloController::getModel()const {
    return static_cast<storage*>(mod);
}

profilo_view* ProfiloController::getView() const{
    return static_cast<profilo_view*>(view) ;
}

void ProfiloController::onViewClosed() const {
    delete this;
}

void ProfiloController::indietro_enter() const {
    if(view->parent()){
        static_cast<View*>(view->parent())->show();
        hide();
        delete this;
    }
}
