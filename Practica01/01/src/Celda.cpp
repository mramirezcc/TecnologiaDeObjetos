#include "Celda.h"

Celda::Celda(int tipo){
    this->tipo = tipo;
}

Celda::Celda(){
    Celda(0);
}

Personaje* Celda::getOcupador(){
    return this->ocupador;
}

void Celda::setOcupador(Personaje* personaje){
    this->ocupador = personaje;
}

void Celda::liberar(){
    this->ocupador = nullptr;
}