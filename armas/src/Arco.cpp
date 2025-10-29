#include "Arco.h"

Arco::Arco(const std::string& nombre, int danioBase, const std::string& elemento, float probCritico)
    : Arma(nombre, danioBase, elemento, probCritico) {}

std::string Arco::getTipo() const {
    return "Arco";
}