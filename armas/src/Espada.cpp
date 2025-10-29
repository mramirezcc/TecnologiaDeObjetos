#include "Espada.h"

Espada::Espada(const std::string& nombre, int danioBase, const std::string& elemento, float probCritico)
    : Arma(nombre, danioBase, elemento, probCritico) {}

std::string Espada::getTipo() const {
    return "Espada";
}