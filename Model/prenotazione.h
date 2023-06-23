#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "aula.h"
#include "utente.h"
#include <string>
#include <QDate>
#include <QTime>

using std::string;

class prenotazione{
private:
    utente* persona;
    QDate data;
    QTime oraArrivo;
    QTime oraUscita;
    string causale;
    aula* aula_pr;

public:
    prenotazione(utente* _persona=nullptr, QDate _data=QDate::currentDate(), QTime _oraArrivo=QTime(8,30), QTime _oraUscita=QTime(19,00), string _causale="", aula* _aula_pr=nullptr);
    virtual ~prenotazione()=default;
    bool operator==(const prenotazione&)const;
    bool operator!=(const prenotazione&)const;
    
    utente* getPersona() const;
    const QDate& getData() const;
    const QTime& getOraArrivo() const;
    const QTime& getOraUscita() const;
    string getCausale() const;
    aula* getAula() const;

    void setPersona(utente* value);
    void setData(const QDate& value);
    void setOraArrivo(const QTime& value);
    void setOraUscita(const QTime& value);
    void setCausale(const string &value);
    void setAula(aula* value);
};

#endif // PRENOTAZIONE_H
