#ifndef AULASTUDIO_H
#define AULASTUDIO_H

#include <Model/aula.h>

class aulaStudio : public aula {
private:
    int leggii;
    int prese_corrente;

public:
    aulaStudio(int _piano=0, int _numero=0, string _sede="", int _max_persone=0, int _leggii=0, int _prese_corrente=0);

    int getLeggii() const;
    int getPreseCorrente() const;

    void setLeggii(const int value);
    void setPrese(const int value);
};

#endif
