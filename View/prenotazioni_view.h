#ifndef PRENOTAZIONI_VIEW_H
#define PRENOTAZIONI_VIEW_H

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

class prenotazioni_view : public View{
private:
    QString mail;
    QTableWidget* pren_table;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* aggiungi;
    QPushButton* indietro;

    QLineEdit* _aula;
    QDateEdit* _data;
    QTimeEdit* _oraArrivo;
    QTimeEdit* _oraUscita;
    QTextEdit* _causale;
    QLabel* _mail;

protected:
    explicit prenotazioni_view();
public:
    explicit prenotazioni_view(const QSize& s, QString& m, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

    void create_table(const QStringList&);
    void carica_pren(const contenitore<prenotazione*>& );

public slots:
    void aggiungi_pren();

signals:
    void indietro_signal() const;
    void aggiungi_signal(const QString&, const QDate&, const QTime&, const QTime&, const QString&, const QString&)const;

};

#endif // PRENOTAZIONI_VIEW_H
