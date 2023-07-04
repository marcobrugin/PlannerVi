#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QObject>
#include"Model/storage.h"
#include "Controller/login_controller.h"
#include "Controller/admin_controller.h"
#include "Controller/menu_controller.h"
#include "Controller/profilo_controller.h"
#include "Controller/prenotazioni_controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    storage* st=new storage();

    login_view* login = new login_view(QSize(500,300),nullptr);
    LoginController* log_controller= new LoginController (st, login);
    log_controller->show();
    /*
    admin_view* aW = new admin_view (QSize(900,600),nullptr);
    AdminController* aC= new AdminController (st, aW, nullptr);
    aC->show();

    menu_view* mW = new menu_view (QSize(900,600),nullptr);
    MenuController* mC= new MenuController (st, mW, nullptr);
    mC->show();

    login_view* login = new login_view(QSize(500,300),nullptr);
    LoginController* log_controller= new LoginController (st, login);
    log_controller->show();

    profilo_view* pW = new profilo_view(QSize(500,300),nullptr);
    ProfiloController* pC= new ProfiloController (st, pW, nullptr);
    pC->show();

    prenotazioni_view* pW = new prenotazioni_view(QSize(500,300),nullptr);
    PrenController* pC= new PrenController (st, pW, nullptr);
    pC->show();
*/


    return QApplication::exec();
}

