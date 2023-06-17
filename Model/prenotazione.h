#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "aula.h"
#include "utente.h"
#include <string>
#include<QDate>

using std::string;

class prenotazione{
private:
    utente* persona;
    QDate data;
    int oraArrivo;
    int oraUscita;
    string causale;
    aula* aula_pr;

public:
    prenotazione(utente* _persona=nullptr, int _oraArrivo=0, int _oraUscita=0, string _causale="", aula* _aula_pr=nullptr);
    virtual ~prenotazione()=default;
    bool operator==(const prenotazione&)const;
    bool operator!=(const prenotazione&)const;
    
    utente* getPersona() const;
    const QDate& getData() const;
    int getOraArrivo() const;
    int getOraUscita() const;
    string getCausale() const;
    aula* getAula() const;

    void setPersona(utente* value);
    void setData(const QDate& value);
    void setOraArrivo(int value);
    void setOraUscita(int value);
    void setCausale(const string &value);
    void setAula(aula* value);
};

#endif // PRENOTAZIONE_H
