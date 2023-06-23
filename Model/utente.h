#ifndef UTENTE_H
#define UTENTE_H

#include <string>

using std::string;

class utente{
private:
    string nome;
    string cognome;
    string codiceFiscale;
    string telefono;
    string email;
    string ruolo;
    string password;

public:
    utente(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", string _ruolo="Studente", string _pw="xyz");
    virtual ~utente() = default;

    string getNome() const;
    void setNome(const string &value);
    string getCognome() const;
    void setCognome(const string &value);
    string getCodiceFiscale() const;
    void setCodiceFiscale(const string &value);
    string getTelefono() const;
    void setTelefono(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
    string getRuolo() const;
    void setRuolo(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
};


#endif // UTENTE_H
