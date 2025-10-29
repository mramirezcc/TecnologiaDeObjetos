#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje {
    private:
        int experiencia;
        int nivel;
    
    public:
        Jugador(const std::string& nombre, int salud, std::unique_ptr<Arma> arma);
        void ganarExperiencia(int exp);
        void subirNivel();
        std::string getTipo() const override;
        int getNivel() const;
        int getExperiencia() const;
};

#endif