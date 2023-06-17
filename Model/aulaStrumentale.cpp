#include "aulaStrumentale.h"

//impl. costruttore
aulaStrumentale::aulaStrumentale(int _piano, int _numero, string _sede, int _max_persone, const string& _strumento)
    : aula(_piano, _numero, _sede, _max_persone), strumento(_strumento) {}

const string& aulaStrumentale::getStrumento() const { return strumento; }

void aulaStrumentale::setStrumento(const string &value){ strumento=value; }
