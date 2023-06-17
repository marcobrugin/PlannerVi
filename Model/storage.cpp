#include "storage.h"

storage::storage(){}
const contenitore<aula*>& storage::getContAula() const{
    return aule;
}
const contenitore<prenotazione*>& storage::getContPren() const{
    return prenotazioni;
}
const vector<utente*>& storage::getUtente() const{
    return pers;
}

storage::storage(contenitore<aula*>& aule_iniziali, contenitore<prenotazione*>& prenotazioni_iniziali, vector<utente*>& utenti_iniziali) {
    // Aggiungi le aule iniziali al contenitore delle aule
    for (auto aula : aule_iniziali) {
        aule.push(aula);
    }

    // Aggiungi le prenotazioni iniziali al contenitore delle prenotazioni
    for (auto prenotazione : prenotazioni_iniziali) {
        prenotazioni.push(prenotazione);
    }

    // Assegna il vettore degli utenti iniziali
    pers = utenti_iniziali;
}


storage::~storage() {
    // Dealloca le aule nel contenitore delle aule
    for (auto aula : aule) {
        delete aula;
    }

    // Dealloca le prenotazioni nel contenitore delle prenotazioni
    for (auto prenotazione : prenotazioni) {
        delete prenotazione;
    }

    // Dealloca gli utenti nel vettore degli utenti
    for (auto utente : pers) {
        delete utente;
    }
}

void storage::addAula(aula* a) {
    aule.insertSorted(a, [](const aula* a1, const aula* a2) {
        if (a1->getPiano() < a2->getPiano()) {
            return true;
        } else if (a1->getPiano() == a2->getPiano()) {
            return a1->getNumero() < a2->getNumero();
        } else {
            return false;
        }
    });
}

void storage::removeAula(aula* aulaToRemove) {
    aule.remove(aulaToRemove);
}

void storage::addPrenotazione(prenotazione* pr) {
    prenotazioni.insertSorted(pr, [](const prenotazione* a, const prenotazione* b) {
        return a->getData() < b->getData();
    });
}

void storage::removePrenotazione(prenotazione* prToRemove) {
    prenotazioni.remove(prToRemove);
}
