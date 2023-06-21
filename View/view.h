#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>
using std::string;

class View:public QWidget //classe base polimorfa, è la base delle altre schermate
{
    Q_OBJECT

protected:
    //costr protected ->non usabili all'esterno
    explicit View(const QSize&, View* =nullptr);
    explicit View();
    View(View&);

public:
    virtual ~View(); //distr virtuale

    //visualizzazione di messaggi all'utente
    void showMessage(const QString&,const QString&) ;
    void showError(const QString&,const QString&);

    void setDim(const QSize&); //setta la dimensione delle schermate

    void setTitolo(const QString &); //setta il titolo della schermata

    void closeEvent(QCloseEvent *) override; //per chiusura schermata

signals:
    void viewClosed() const; //close_signal to controller
};

#endif // VIEW_H
