#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "view.h"
#include "Model/storage.h"
#include <QTableWidget>

class admin_view: public View {
    Q_OBJECT
private:
    QTableWidget* tabella;

public:
    explicit admin_view(const QSize& s, View *parent = nullptr);
    void visualizza_prenotazioni(contenitore<prenotazione*>& ) const;

signals:
    void aggiornaPagina_signal();

    void showPren_signal(const pren_item* pr);
    void modificaPren_signal(const pren_item* pr);
    void eliminaPren_signal(const pren_item* pr);
};

#endif // ADMIN_VIEW_H
