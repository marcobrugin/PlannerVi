#ifndef PROFILO_VIEW_H
#define PROFILO_VIEW_H

#include "view.h"
#include "Model/utente.h"
#include <QObject>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class profilo_view : public View {
    Q_OBJECT
private:
    QGridLayout* layout;
    QPushButton* indietro;
    const utente* persona;
protected:
    explicit profilo_view();

public:
    explicit profilo_view(const QSize& s, const utente* m, View *parent = nullptr );
    void closeEvent(QCloseEvent *event) override;

signals:
    void indietro_signal() const;
};

#endif // PROFILO_VIEW_H
