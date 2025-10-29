#ifndef HACHA_H
#define HACHA_H

#include "Arma.h"

class Hacha : public Arma {
    public:
        Hacha(const std::string& nombre, int danioBase, const std::string& elemento = "Normal", float probCritico = 0.2f);
        std::string getTipo() const override;
        int calcularDanio() const override; // Hacha tiene cálculo de daño diferente
};

#endif