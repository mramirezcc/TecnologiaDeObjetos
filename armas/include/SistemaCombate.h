#ifndef SISTEMACOMBATE_H
#define SISTEMACOMBATE_H

#include "Jugador.h"
#include "Enemigo.h"
#include <vector>

class SistemaCombate {
    public:
        static void iniciarCombate(Jugador& jugador, Enemigo& enemigo);
        static void mostrarEstado(const Personaje& personaje);
};

#endif