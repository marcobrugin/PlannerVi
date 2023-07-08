#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "aula.h"
#include <string>
#include <QDate>
#include <QTime>

using std::string;

class prenotazione{
private:
    string persona;
    QDate data;
    QTime oraArrivo;
    QTime oraUscita;
    string causale;
    int aula_pr;

public:
    prenotazione(string _persona="", QDate _data=QDate::currentDate(), QTime _oraArrivo=QTime(8,30), QTime _oraUscita=QTime(19,00), string _causale="", int _aula_pr=0);
    virtual ~prenotazione()=default;
    bool operator==(const prenotazione&)const;
    bool operator!=(const prenotazione&)const;
    
    string getPersona() const;
    const QDate& getData() const;
    const QTime& getOraArrivo() const;
    const QTime& getOraUscita() const;
    string getCausale() const;
    int getAula() const;

    void setPersona(const string &value);
    void setData(const QDate& value);
    void setOraArrivo(const QTime& value);
    void setOraUscita(const QTime& value);
    void setCausale(const string &value);
    void setAula(const int value);
};

#endif // PRENOTAZIONE_H
