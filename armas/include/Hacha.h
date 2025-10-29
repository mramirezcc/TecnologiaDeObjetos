#ifndef HACHA_H
#define HACHA_H

#include "Arma.h"

class Hacha : public Arma {
    public:
        Hacha(const std::string& nombre, int dmgBase, const std::string& elem = "Normal", float probCritico = 0.2f);
        std::string getTipo() const override;
        // Hacha calcula diferente
        int calcularDmg() const override;
};

#endif