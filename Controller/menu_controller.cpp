#include "menu_controller.h"

MenuController::MenuController(storage* s, menu_view * m, Controller* c) : Controller(s, m, c){
    connect(view,SIGNAL(View_profilo_signal()),this,SLOT(Profilo_enter()));
    connect(view,SIGNAL(View_my_signal()),this,SLOT(MyPren_enter()));
    connect(view,SIGNAL(View_tutte_signal()),this,SLOT(Pren_enter()));
}

void MenuController::AulaView() const {}

storage* MenuController::getModel() const{
    return static_cast<storage*>(mod);
}
menu_view* MenuController::getView() const {
    return static_cast<menu_view*>(view) ;
}

void MenuController::Profilo_enter() const {
    profilo_view* newW =new profilo_view(QSize(300,400), view);
    newW->show();
    hide();
}
void MenuController::MyPren_enter() const {
    myPren_view* newW =new myPren_view(QSize(300,400), view);
    newW->show();
    hide();
}
void MenuController::Pren_enter() const {
    prenotazioni_view* newW =new prenotazioni_view(QSize(300,400), view);
    newW->show();
    hide();
}

void MenuController::onViewClosed() const {
    delete this;
}
