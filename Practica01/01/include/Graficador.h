#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include "Celda.h"

class Graficador{
    private:
        Celda** tablero;
        int filas;
        int columnas;
    public:
        Graficador(Celda** tab, int filas, int columnas);
        void graficar();
};

#endif