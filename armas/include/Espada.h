#ifndef ESPADA_H
#define ESPADA_H

#include "Arma.h"

class Espada : public Arma {
    public:
        Espada(const std::string& nombre, int dmgBase, const std::string& elem = "Normal", float probCritico = 0.1f);
        std::string getTipo() const override;
};

#endif