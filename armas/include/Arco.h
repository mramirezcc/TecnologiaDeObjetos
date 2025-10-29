#ifndef ARCO_H
#define ARCO_H

#include "Arma.h"

class Arco : public Arma {
    public:
        Arco(const std::string& nombre, int danioBase, const std::string& elemento = "Normal", float probCritico = 0.15f);
        std::string getTipo() const override;
};

#endif