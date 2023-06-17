#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QObject>
//#include "View/login_view.h"
//#include "View/registrazione_view.h"
#include "View/menu_view.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*login_view* l = new login_view(QSize(500,500),nullptr);
    l->show();

    registrazione_view* r= new registrazione_view(QSize(500,500),nullptr);
    r->show();
    */
    menu_view* m = new menu_view(QSize(500,500),nullptr);
    m->show();

    return QApplication::exec();

}
