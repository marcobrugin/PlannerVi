#ifndef PRENOTAZIONI_CONTROLLER_H
#define PRENOTAZIONI_CONTROLLER_H

#include "controller.h"
#include "menu_controller.h"
#include "View/prenotazioni_view.h"
#include "View/menu_view.h"
#include "Model/storage.h"

class PrenController : public Controller {
    Q_OBJECT
protected:
    explicit PrenController();
public:
    explicit PrenController(storage*, prenotazioni_view*, Controller* = nullptr);
    storage* getModel() const override;
    prenotazioni_view* getView() const override;
public slots:
    void aggiungi_enter(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&) const;
    void indietro_enter() const;
    void rimuovi_enter(uint i);
    void onViewClosed() const override;
};

#endif // PRENOTAZIONI_CONTROLLER_H
