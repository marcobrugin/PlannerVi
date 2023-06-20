#ifndef PROFILO_VIEW_H
#define PROFILO_VIEW_H

#include "view.h"
#include "Model/utente.h"
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class profilo_view : public View {
    Q_OBJECT
private:
    QHBoxLayout* hbox;
    QVBoxLayout* vbox1;
    QVBoxLayout* vbox2;
    QPushButton* indietro;
    QString mail;
protected:
    explicit profilo_view();

public:
    explicit profilo_view(const QSize& s, QString m, View *parent = nullptr );
    void closeEvent(QCloseEvent *event) override;

signals:
    void indietro_signal() const;
};

#endif // PROFILO_VIEW_H
