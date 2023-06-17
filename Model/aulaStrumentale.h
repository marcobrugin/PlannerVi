#ifndef AULASTRUMENTALE_H
#define AULASTRUMENTALE_H

#include <Model/aula.h>

class aulaStrumentale : public aula {
private:
    string strumento;

public:
    aulaStrumentale(int _piano=0, int _numero=0, string _sede="", int _max_persone=0, const string& _strumento="");

    const string& getStrumento() const;

    void setStrumento(const string &value);
};

#endif
