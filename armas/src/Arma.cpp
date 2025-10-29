#include "Arma.h"
#include <random>

Arma::Arma(const std::string& nombre, int danioBase, const std::string& elemento, float probCritico)
    : nombre(nombre), danioBase(danioBase), elemento(elemento), probabilidadCritico(probCritico) {}

int Arma::calcularDanio() const {
    int danio = danioBase;
    if (esCritico()) {
        danio *= 2; // Daño crítico duplica el daño
    }
    return danio;
}

std::string Arma::getNombre() const {
    return nombre;
}

std::string Arma::getElemento() const {
    return elemento;
}

bool Arma::esCritico() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < probabilidadCritico;
}