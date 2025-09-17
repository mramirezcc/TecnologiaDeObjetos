#ifndef JUEGO_H
#define JUEGO_H

#include "Celda.h"

class Juego{
    private:
        int filas = 20;
        int columnas = 20;
        Celda** tab;
    public:
        Juego(Celda** tab, int filas, int columnas);
        static int randomInt(int min, int max);
        void inicializarTablero();
        void llenarTabla();
        void ciclo();
        void recortarZona(int contador, int numCiclos);
};

#endif