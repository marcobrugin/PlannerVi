#include "aulaStudio.h"

// Implementazione del costruttore di AulaStudio
aulaStudio::aulaStudio(int _piano, int _numero, string _sede, int _max_persone, int _leggii, int _prese)
    : aula(_piano, _numero, _sede, _max_persone), leggii(_leggii), prese_corrente(_prese) {
}

int aulaStudio::getLeggii() const { return leggii; }
int aulaStudio::getPreseCorrente() const { return prese_corrente; }

void aulaStudio::setLeggii(const int value){ leggii=value; }
void aulaStudio::setPrese(const int value){ prese_corrente=value;}
