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
#include <QRegularExpressionValidator>

class prenotazioni_view : public View{
    Q_OBJECT
private:
    QString mail;
    QTableWidget* pren_table;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* aggiungi;
    QPushButton* indietro;
    QRegularExpressionValidator* validator;

    QLineEdit* _aula;
    QDateEdit* _data;
    QTimeEdit* _oraArrivo;
    QTimeEdit* _oraUscita;
    QTextEdit* _causale;
    QLabel* _mail;

protected:
    explicit prenotazioni_view();
public:
    explicit prenotazioni_view(const QSize& s, const QString& m, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

    void create_table(const QStringList&);
    void carica_pren(const contenitore<prenotazione*>& );
    void addToView(prenotazione*);

public slots:
    void aggiungi_pren();

signals:
    void ButtonClicked() const;
    void indietro_signal() const;
    void aggiungi_signal(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&);
    void rimuovi_signal(uint);
};

#endif // PRENOTAZIONI_VIEW_H
