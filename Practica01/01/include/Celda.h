#ifndef CELDA_H
#define CELDA_H

#include "Personaje.h"

class Celda{
    private:
        // 0 - vacio
        // 1 - roca
        int tipo;
        Personaje* ocupador;


    public:
        Celda(int tipo);
        Celda();
        Personaje* getOcupador();
        void setOcupador(Personaje* personaje);
        void liberar();
};

#endif