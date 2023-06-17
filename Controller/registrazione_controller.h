#ifndef REGISTRAZIONE_CONTROLLER_H
#define REGISTRAZIONE_CONTROLLER_H

#include "controller.h"
#include "Model/storage.h"
#include "View/registrazione_view.h"
#include "View/login_view.h"

class RegController : public Controller {
    Q_OBJECT
protected:
    RegController();
public:
    RegController(registrazione_view*, Controller* = nullptr);
    storage* getModel() const override;
    login_view* getView() const override;
public slots:
    void Registr_enter(QString _nome, QString _cogn) const;
    void onViewClosed() const override;
};

#endif // REGISTRAZIONE_CONTROLLER_H
