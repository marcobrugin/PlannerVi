#include <iostream>
#include <vector>

#include "aula.h"

// Implementazione del costruttore di Aula
aula::aula(int _piano, int _numero, string _sede, int _max_persone)
    : piano(_piano), numero(_numero), sede(_sede), max_persone(_max_persone) {}

aula::~aula(){}

// Implementazione dei metodi get
int aula::getPiano() const { return piano; }
int aula::getNumero() const { return numero; }
string aula::getSede() const { return sede; }
int aula::getMaxPersone() const { return max_persone; }

//implem metodi set
void aula::setPiano(const int value) {
    piano=value;
}
void aula::setNumero(int value){
    numero=value;
}
void aula::setSede(const string &value){
    sede=value;
}
void aula::setMaxPersone(int value){
    max_persone=value;
}


