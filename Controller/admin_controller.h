#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "controller.h"
#include "View/admin_view.h"
#include "Model/storage.h"

class AdminController: public Controller {
    Q_OBJECT
protected:
    explicit AdminController();
public:
    explicit AdminController(storage*, admin_view*, Controller* = nullptr);
    storage* getModel() const override;
    admin_view* getView() const override;
public slots:
    void aggiungi_enter(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&) const;
    void rimuovi_enter(uint i);
    void onViewClosed() const override;
};

#endif // ADMIN_CONTROLLER_H
