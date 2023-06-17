#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "controller.h"
#include "View/menu_view.h"
#include "Model/storage.h"

class MenuController : public Controller {
    Q_OBJECT
protected:
    MenuController();
public:
    MenuController(storage* , menu_view* , Controller* = nullptr);
    void AulaView() const;
    void PrenView() const;
    storage* getModel() const override;
    menu_view* getView() const override;
public slots:
    void Profilo_enter() const;
    void MyPren_enter() const;
    void Pren_enter() const;
    void onViewClosed() const override;
};

#endif // MENU_CONTROLLER_H
