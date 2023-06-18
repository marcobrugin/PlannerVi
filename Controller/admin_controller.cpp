#include "admin_controller.h"

AdminController::AdminController(){}

AdminController::AdminController(storage* s, admin_view * a, Controller* c) : Controller(s, a, c){
    //connect(view,SIGNAL(Login_signal(em, pass)),this,SLOT(Login_enter(em, pass)));
    //connect(view,SIGNAL(Label_signal()),this,SLOT(Label_enter()));
}
storage* AdminController::getModel()const {
    return static_cast<storage*>(mod);
}

admin_view* AdminController::getView() const{
    admin_view static_cast<admin_view*>(view) ;
}
void AdminController::onViewClosed() const {
    delete this;
}
