#include "Arma.h"
#include <random>

Arma::Arma(const std::string& nombre, int dmgBase, const std::string& elem, float probCritico)
    : nombre(nombre), dmgBase(dmgBase), elem(elem), probCrit(probCritico) {}

int Arma::calcularDmg() const {
    int dmg = dmgBase;
    if (esCritico()) {
        dmg *= 2; // Daño crítico duplica el daño
    }
    return dmg;
}

std::string Arma::getNombre() const {
    return nombre;
}

std::string Arma::getElem() const {
    return elem;
}

bool Arma::esCritico() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < probCrit;
}