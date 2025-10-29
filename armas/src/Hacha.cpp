#include "Hacha.h"
#include <random>

Hacha::Hacha(const std::string& nombre, int danioBase, const std::string& elemento, float probCritico)
    : Arma(nombre, danioBase, elemento, probCritico) {}

std::string Hacha::getTipo() const {
    return "Hacha";
}

int Hacha::calcularDanio() const {
    // Hacha tiene posibilidad de daño adicional por romper defensas
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    int danio = danioBase;
    
    if (esCritico()) {
        danio *= 3; // Hacha tiene crítico más fuerte
    }
    
    // 30% de probabilidad de daño extra
    if (dis(gen) < 0.3f) {
        danio += danioBase * 0.5; // 50% de daño extra
    }
    
    return danio;
}