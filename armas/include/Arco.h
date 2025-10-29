#ifndef ARCO_H
#define ARCO_H

#include "Arma.h"

class Arco : public Arma {
    public:
        Arco(const std::string& nombre, int dmgBase, const std::string& elem = "Normal", float probCritico = 0.15f);
        std::string getTipo() const override;
};

#endif