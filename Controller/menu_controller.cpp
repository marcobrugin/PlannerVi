#include "menu_controller.h"

MenuController::MenuController(storage* s, menu_view * m, Controller* c) : Controller(s, m, c){
    connect(view,SIGNAL(View_aule_signal()),this,SLOT(AulaView()));
    connect(view,SIGNAL(View_pren_signal()),this,SLOT(PrenView()));
}

void MenuController::AulaView() const {

}
storage* MenuController::getModel() const{
    return static_cast<storage*>(mod);
}
menu_view* MenuController::getView() const {
    return static_cast<menu_view*>(view) ;
}
void MenuController::onViewClosed() const {
    delete this;
}
