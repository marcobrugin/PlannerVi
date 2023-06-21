#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "view.h"
#include "Model/storage.h"

#include <QObject>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>

class admin_view: public View {
    Q_OBJECT
private:
    QTableWidget* pren_table;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* aggiungi;
    QPushButton* rimuovi;
    QPushButton* indietro;

    QLineEdit* _aula;
    QDateEdit* _data;
    QTimeEdit* _oraArrivo;
    QTimeEdit* _oraUscita;
    QTextEdit* _causale;
    QTextEdit* _mail;

protected:
    explicit admin_view();

public:
    explicit admin_view(const QSize& s, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

    void create_table(const QStringList&);
    void visualizza_prenotazioni(const contenitore<prenotazione*>& );
    void rimuovi_prenotazione(uint);

public slots:
    void aggiungi_pren();

signals:
    void rimuovi_signal(uint);
};

#endif // ADMIN_VIEW_H
