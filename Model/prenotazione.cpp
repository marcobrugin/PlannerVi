#include "prenotazione.h"

prenotazione::prenotazione(string _persona, QDate _data, QTime _oraArrivo, QTime _oraUscita, string _causale, int _aula_pr)
    : persona(_persona), data(_data), oraArrivo(_oraArrivo), oraUscita(_oraUscita), causale(_causale), aula_pr(_aula_pr){};

bool prenotazione::operator==(const prenotazione &_pr) const{
    return (_pr.persona==persona && _pr.data==data && _pr.oraArrivo==oraArrivo && _pr.oraUscita==oraUscita && _pr.causale==causale);
}

bool prenotazione::operator!=(const prenotazione &_pr) const{
    return !(*this==_pr);
}

//impl metodi get
string prenotazione::getPersona() const { return persona; };
const QDate& prenotazione::getData() const { return data; }
const QTime& prenotazione::getOraArrivo() const { return oraArrivo; };
const QTime& prenotazione::getOraUscita() const { return oraUscita; };
string prenotazione::getCausale() const { return causale; };
int prenotazione::getAula() const { return aula_pr; }

//impl metodi set
void prenotazione::setPersona(const string &value){ persona=value; }
void prenotazione::setData(const QDate& value){ data=value; }
void prenotazione::setOraArrivo(const QTime& value){ oraArrivo=value; }
void prenotazione::setOraUscita(const QTime& value){ oraUscita=value; }
void prenotazione::setCausale(const string &value){ causale=value; }
void prenotazione::setAula(const int value){ aula_pr=value; }
