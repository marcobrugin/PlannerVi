#ifndef AULA_H
#define AULA_H

#include<string>
using std::string;

class aula {
private:
    int piano;
    int numero;
    string sede;
    int max_persone;

public:
    aula(int _piano=0, int numero=0, string _sede="", int _max_persone=0);
    virtual ~aula();
    virtual aula* clone() const = 0;

    //metodi get
    int getPiano() const;
    int getNumero() const;
    string getSede() const;
    int getMaxPersone() const;

    //metodi set
    void setPiano(const int value);
    void setNumero(int value);
    void setSede(const string &value);
    void setMaxPersone(int value);

};

#endif // AULA_H

