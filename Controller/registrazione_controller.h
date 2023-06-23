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
    RegController(storage*, registrazione_view*, Controller* = nullptr);
    storage* getModel() const override;
    registrazione_view* getView() const override;
public slots:
    void Registr_enter(const QString& _nome, const QString& _cogn, const QString& _cod, const QString& _ph, const QString& _mail, const QString& _pass ) const;
    void onViewClosed() const override;
};

#endif // REGISTRAZIONE_CONTROLLER_H
