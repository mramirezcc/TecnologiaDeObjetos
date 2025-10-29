#include "Espada.h"

Espada::Espada(const std::string& nombre, int dmgBase, const std::string& elem, float probCritico)
    : Arma(nombre, dmgBase, elem, probCritico) {}

std::string Espada::getTipo() const {
    return "Espada";
}