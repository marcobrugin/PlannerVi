#ifndef AULACONCERTO_H
#define AULACONCERTO_H

#include <Model/aula.h>

class aulaConcerto : public aula {
private:
    string nome_aula;
    string strumento;
    int capienza;
    bool amplificazione; //0=false, 1=true

public:
    aulaConcerto(int _piano=0, int _numero=0, string _sede="", int _max_persone=0, const string& _nome_aula="", const string& _strumento="", int _capienza=0, bool _amplificazione=0 );

    //metodi get
    const string& getNome() const;
    const string& getStrumento() const;
    int getCapienza() const;
    bool getAmplificazione() const;

    //metodi set
    void setNome(const string &value);
    void setStrumento(const string &value);
    void setCapienza(const int value);
    void setAmplificazione(bool value);
};

#endif
