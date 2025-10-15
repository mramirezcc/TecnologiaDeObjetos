#ifndef EQUIPO_H
#define EQUIPO_H

#include "Personaje.h"
#include <vector>

class Equipo {
    private:
        static std::vector<Equipo*> equipos;
        std::vector<Personaje*> personajes;
    public:
        Equipo();
        ~Equipo();
        void showEquipos();
};

#endif