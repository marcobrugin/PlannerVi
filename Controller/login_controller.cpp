#include "login_controller.h"

LoginController::LoginController(storage* s, login_view * l, Controller* c) : Controller(s, l, c){
    view->setTitolo("SCHEDA DI LOGIN");

    connect(view,SIGNAL(Login_signal(string, string)),this,SLOT(Login_enter(string, string)));
    connect(view,SIGNAL(Register_signal()),this,SLOT(Register_enter()));
}
 storage* LoginController::getModel()const {
    return static_cast<storage*>(mod);
}

 login_view* LoginController::getView() const{
    return static_cast<login_view*>(view) ;
}
 void LoginController::onViewClosed() const {
    delete this;
 }

void LoginController::Login_enter(const string& em, const string& pass) const {
    bool find=1;
    for(auto it: getModel()->getUtente()){
        if(it->getEmail()==em){ //trova corrispondenza email nello storage
            find=0;
            if(it->getPassword()==pass){ //controllo correttezza password
                //CONTROLLO SUL UTENTE VS ADMIN PER LA VISUALIZZAZIONE DELLA RELATIVA SCHEDA
                if(it->getEmail()=="admin"){
                    admin_view* aW = new admin_view(QSize(300,400), view);
                    AdminController* aC = new AdminController(getModel() , aW , const_cast<LoginController*>(this));
                    aC->show();
                    hide();
                }
                else{
                menu_view* menuW = new menu_view(QSize(300,400), QString::fromStdString(em), view); //posso passargli pure la mail dell'utente?
                MenuController* menuC = new MenuController(getModel() , menuW , const_cast<LoginController*>(this));
                menuC->show();
                hide();
                }
            }
            else{
                view->showError("Errore","Password errata");
            }
        }
    }
    if(find==1){
        view->showError("Errore","Email errata");
    }
}

void LoginController::Register_enter() const {
    registrazione_view* regW =new registrazione_view(QSize(300,400), view);
    RegController* regC = new RegController(getModel() , regW , const_cast<LoginController*>(this));
    regC->show();
    hide();
}
