#include "Hacha.h"
#include <random>

Hacha::Hacha(const std::string& nombre, int dmgBase, const std::string& elem, float probCritico)
    : Arma(nombre, dmgBase, elem, probCritico) {}

std::string Hacha::getTipo() const {
    return "Hacha";
}

int Hacha::calcularDmg() const {
    // Hacha tiene posibilidad de daño adicional por romper defensas
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    int dmg = dmgBase;
    
    if (esCritico()) {
        dmg *= 3;
    }
    
    if (dis(gen) < 0.3f) {
        dmg += dmgBase * 0.5;
    }
    
    return dmg;
}