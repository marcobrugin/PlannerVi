#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QObject>
#include"Model/storage.h"
#include "View/view.h"
#include "View/login_view.h"
#include "Controller/login_controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    storage* st=new storage();
    login_view* login = new login_view(QSize(500,300),nullptr);
    login->show();
    LoginController* log_controller= new LoginController (st, login);
    log_controller->show();

    //registrazione_view* r= new registrazione_view(QSize(500,500),nullptr);
    //r->show();

    //menu_view* m = new menu_view(QSize(500,500),nullptr);
    //m->show();

    return QApplication::exec();
}

