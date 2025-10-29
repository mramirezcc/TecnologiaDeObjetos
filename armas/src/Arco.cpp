#include "Arco.h"

Arco::Arco(const std::string& nombre, int dmgBase, const std::string& elem, float probCritico)
    : Arma(nombre, dmgBase, elem, probCritico) {}

std::string Arco::getTipo() const {
    return "Arco";
}