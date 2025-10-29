#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje {
    private:
        std::string tipoEnemigo;
        int recompensaExperiencia;
    
    public:
        Enemigo(const std::string& nombre, int salud, std::unique_ptr<Arma> arma, 
                const std::string& tipoEnemigo, int recompensaExp);
        std::string getTipo() const override;
        std::string getTipoEnemigo() const;
        int getRecompensaExperiencia() const;
};

#endif