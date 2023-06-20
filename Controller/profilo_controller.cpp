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
    menu_view* menuW =new menu_view(QSize(300,400), view);
    menuW->show();
    hide();
}
