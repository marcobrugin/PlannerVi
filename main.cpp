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

    /*LoginWindow* l = new LoginWindow(QSize(500,500),nullptr);
    l->show();

    RegistrationWindow* r= new RegistrationWindow(QSize(500,500),nullptr);
    r->show();
    */
    MenuWindow* m = new MenuWindow(QSize(500,500),nullptr);
    m->show();

    return QApplication::exec();

}
