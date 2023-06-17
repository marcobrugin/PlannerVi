#include "aulaConcerto.h"

// Impl. costruttore di AulaConcerto
aulaConcerto::aulaConcerto(int _piano, int _numero, string _sede, int _max_persone, const string& _nome_aula, const string& _strumento, int _capienza, bool _amplificazione )
    : aula(_piano, _numero, _sede, _max_persone), nome_aula(_nome_aula), strumento(_strumento), capienza(_capienza), amplificazione(_amplificazione) {}

//impl metodi get
const string& aulaConcerto::getNome() const { return nome_aula; }
const string& aulaConcerto::getStrumento() const { return strumento; }
int aulaConcerto::getCapienza() const { return capienza; }
bool aulaConcerto::getAmplificazione() const { return amplificazione; }

//implem metodi set
void aulaConcerto::setNome(const string &value) { nome_aula=value; }
void aulaConcerto::setStrumento(const string &value){ strumento=value; }
void aulaConcerto::setCapienza(const int value){ capienza=value; }
void aulaConcerto::setAmplificazione(bool value){ amplificazione=value; }
