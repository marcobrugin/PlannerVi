#include "prenotazione.h"

prenotazione::prenotazione(utente* _persona, int _oraArrivo, int _oraUscita, string _causale, aula* _aula_pr)
    : persona(_persona), oraArrivo(_oraArrivo), oraUscita(_oraUscita), causale(_causale), aula_pr(_aula_pr){};

bool prenotazione::operator==(const prenotazione &_pr) const{
    return (_pr.persona==persona && _pr.oraArrivo==oraArrivo && _pr.oraUscita==oraUscita && _pr.causale==causale);
}

bool prenotazione::operator!=(const prenotazione &_pr) const{
    return !(*this==_pr);
}

//impl metodi get
utente* prenotazione::getPersona() const { return persona; };
const QDate& prenotazione::getData() const { return data; }
int prenotazione::getOraArrivo() const { return oraArrivo; };
int prenotazione::getOraUscita() const { return oraUscita; };
string prenotazione::getCausale() const { return causale; };
aula* prenotazione::getAula() const { return aula_pr; }

//impl metodi set
void prenotazione::setPersona(utente* value){ persona=value; }
void prenotazione::setData(const QDate& value){ data=value; }
void prenotazione::setOraArrivo(int value){ oraArrivo=value; }
void prenotazione::setOraUscita(int value){ oraUscita=value; }
void prenotazione::setCausale(const string &value){ causale=value; }
void prenotazione::setAula(aula* value){ aula_pr=value; }
