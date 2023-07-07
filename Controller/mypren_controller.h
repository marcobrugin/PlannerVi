#ifndef MYPREN_CONTROLLER_H
#define MYPREN_CONTROLLER_H

#include "controller.h"
#include "View/mypren_view.h"
#include "Model/storage.h"
#include "Controller/menu_controller.h"

class MyPrenController: public Controller {
    Q_OBJECT

protected:
    explicit MyPrenController();

public:
    explicit MyPrenController(storage*, myPren_view*, Controller* = nullptr);
    storage* getModel() const override;
    myPren_view* getView() const override;

public slots:
    void aggiungi_enter(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&) const;
    void rimuovi_enter(uint i);
    void indietro_enter();
    void onViewClosed() const override;
};

#endif // MYPREN_CONTROLLER_H
