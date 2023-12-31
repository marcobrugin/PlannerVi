#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "controller.h"
#include "registrazione_controller.h"
#include "menu_controller.h"
#include "admin_controller.h"
#include "View/login_view.h"
#include "View/menu_view.h"
#include "View/registrazione_view.h"
#include "View/admin_view.h"
#include "Controller/salvataggio_dati.h"
#include "Model/storage.h"

class LoginController : public Controller {
    Q_OBJECT
protected:
    explicit LoginController();
public:
    explicit LoginController(storage*, login_view*, Controller* = nullptr);
    storage* getModel() const override;
    login_view* getView() const override;
public slots:
    void Login_enter(const string& em, const string& pass) const;
    void Register_enter() const;
    void onViewClosed() const override;
};

#endif // LOGIN_CONTROLLER_H
