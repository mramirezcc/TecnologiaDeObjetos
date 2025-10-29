#include "Personaje.h"

Personaje::Personaje(const std::string& nombre, int salud, std::unique_ptr<Arma> arma)
    : nombre(nombre), salud(salud), saludMaxima(salud), arma(std::move(arma)) {}

void Personaje::recibirDanio(int danio) {
    salud -= danio;
    if (salud < 0) salud = 0;
}

int Personaje::atacar() const {
    return arma ? arma->calcularDanio() : 0;
}

bool Personaje::estaVivo() const {
    return salud > 0;
}

std::string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getSalud() const {
    return salud;
}

std::string Personaje::getTipoArma() const {
    return arma ? arma->getTipo() : "Sin arma";
}

void Personaje::cambiarArma(std::unique_ptr<Arma> nuevaArma) {
    arma = std::move(nuevaArma);
}