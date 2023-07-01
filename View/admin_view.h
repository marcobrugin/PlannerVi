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
#include <QRegularExpressionValidator>

class admin_view: public View {
    Q_OBJECT
private:
    QTableWidget* pren_table;
    QVBoxLayout* vbox;
    QPushButton* aggiungi;
    QPushButton* indietro;

    QRegularExpressionValidator* validator;
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
    void addToView(prenotazione*);
    void rimuovi_prenotazione(uint);

public slots:
    void aggiungi_pren();

signals:
    void ButtonClicked() const;
    void aggiungi_signal(const int& aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail);
    void rimuovi_signal(uint);
    void elimina_signal(uint);
};

#endif // ADMIN_VIEW_H
