#ifndef PROFILO_CONTROLLER_H
#define PROFILO_CONTROLLER_H

#include "controller.h"
#include "menu_controller.h"
#include "View/profilo_view.h"
#include "View/menu_view.h"
#include "Model/storage.h"

class ProfiloController : public Controller {
    Q_OBJECT
protected:
    ProfiloController();
public:
    ProfiloController(storage*, profilo_view*, Controller* = nullptr);
    storage* getModel() const override;
    profilo_view* getView() const override;
public slots:
    void indietro_enter() const;
    void onViewClosed() const override;
};

#endif // PROFILO_CONTROLLER_H
