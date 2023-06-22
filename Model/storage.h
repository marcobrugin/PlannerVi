#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>
#include<vector>
#include<string>
#include "contenitore.h"
#include "aula.h"
#include "prenotazione.h"
#include "utente.h"
#include "model.h"

using std::vector;


class storage: public Model{
private:
    contenitore<aula*> aule;
    contenitore<prenotazione*> prenotazioni;
    vector<utente*> pers;
protected:
    explicit storage();
public:
    storage(contenitore<aula*>& , contenitore<prenotazione*>& , vector<utente*>& );//costr
    virtual ~storage();//distr

    const contenitore<aula*>& getContAula() const;
    const contenitore<prenotazione*>& getContPren() const;
    const vector<utente*>& getUtente() const;

    void addAula(aula* aula);
    void removeAula(aula* aula);
    aula* searchAula(const int piano, const int numero);

    void addPrenotazione(prenotazione* pr);
    void removePrenotazione(uint i);
    prenotazione* searchPrenotazione(const QDate& data, const aula* aulaRiferimento);

    void addUtente(utente* ut);
    void removeUtente(const string& nome, const string& cognome);
    void modifyUtente(const string& nome, const string& cognome, const string& nuovoTelefono, const string& nuovaEmail);
};


#endif // STORAGE_H
