#include "Model/utente.h"

utente::utente(string _nome, string _cognome, string _codiceFiscale, string _telefono, string _email, string _ruolo, string _pw)
    :nome(_nome), cognome(_cognome), codiceFiscale(_codiceFiscale), telefono(_telefono), email(_email), ruolo(_ruolo), password(_pw){}

string utente::getNome() const { return nome; }
void utente::setNome(const string &value) { 
    nome=value; 
}
string utente::getCognome() const { return cognome; }
void utente::setCognome(const string &value){
    cognome=value;
}
string utente::getCodiceFiscale() const { return codiceFiscale; }
void utente::setCodiceFiscale(const string &value){
    codiceFiscale=value;
}
string utente::getTelefono() const { return telefono; }
void utente::setTelefono(const string &value){
    telefono=value;
}
string utente::getEmail() const { return email; }
void utente::setEmail(const string &value){
    email=value;
}
string utente::getRuolo() const { return ruolo; }
void utente::setRuolo(const string &value){
    ruolo=value;
}
string utente::getPassword() const { return password; }
void utente::setPassword(const string &value){
    password=value;
}
