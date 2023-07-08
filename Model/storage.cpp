#include "storage.h"
#include "contenitore.h"

storage::storage(){
    aule=contenitore<aula*>();
    prenotazioni=contenitore<prenotazione*>();
}

storage::storage(QJsonDocument* document): aule(contenitore<aula*>()), prenotazioni(contenitore<prenotazione*>()){
    /* QJsonObject JObject = document->object();
    QJsonArray JArray_aule = JObject["aule"].toArray();
    for (auto i: JArray_aule){
        aula* a= new aula();
    }

    QJsonArray JArray_pren = JObject["prenotazioni"].toArray();
    for (auto i: JArray_pren){
        prenotazione* pren= new prenotazione(i.toObject().value("Persona"),
                                            i.toObject().value("Data").toString(),
                                            i.toObject().value("OraArrivo").toString(),
                                            i.toObject().value("OraUscita").toString(),
                                            i.toObject().value("Causale"),
                                            i.toObject().value("Aula").toString());
    }

    QJsonArray JArray_ut = JObject["utenti"].toArray();
    for (auto i: JArray_aule){
        utente* ut= new utente(i.toObject().value("Nome"),
                                i.toObject().value("Cognome"),
                                i.toObject().value("CodFiscale"),
                                i.toObject().value("Telefono"),
                                i.toObject().value("Email"),
                                i.toObject().value("Ruolo"),
                                i.toObject().value("Password"));
    }
*/

}

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
        return a->getData() < b->getData() && a->getAula() < b->getAula() && a->getOraArrivo() < b->getOraArrivo();
    });
}

void storage::removePrenotazione(uint i) {
    prenotazioni.remove(i);
}

void storage::addUtente(utente* ut){
    pers.push_back(ut);
}

