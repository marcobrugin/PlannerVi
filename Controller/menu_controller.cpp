#include "menu_controller.h"

MenuController::MenuController(storage* s, menu_view * m, Controller* c) : Controller(s, m, c){
    view->setTitolo("MENU");
    connect(view,SIGNAL(View_profilo_signal(mail)),this,SLOT(Profilo_enter(mail))); //modificare anche l'origine
    //connect(view,SIGNAL(View_my_signal()),this,SLOT(MyPren_enter()));
    connect(view,SIGNAL(View_tutte_signal()),this,SLOT(Pren_enter()));
}

void MenuController::AulaView() const {}

storage* MenuController::getModel() const{
    return static_cast<storage*>(mod);
}
menu_view* MenuController::getView() const {
    return static_cast<menu_view*>(view) ;
}

void MenuController::Profilo_enter(const QString& mail) const {
    //estrapolare dalla mail l'utente
    utente* persona=nullptr;
    for(auto i: getModel()->getUtente()){
        if(i->getEmail()==(mail).toStdString()){
            persona=i;
        }
    }
    profilo_view* newW =new profilo_view(QSize(300,400), persona, view);
    newW->show();
    hide();
}
/*void MenuController::MyPren_enter() const {
    myPren_view* newW =new myPren_view(QSize(300,400), view);
    newW->show();
    hide();
}
*/
void MenuController::Pren_enter(const QString& mail) const {
    prenotazioni_view* newW =new prenotazioni_view(QSize(300,400), mail, view);
    newW->show();
    hide();
}

void MenuController::onViewClosed() const {
    delete this;
}
