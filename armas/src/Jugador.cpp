#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, int salud, std::unique_ptr<Arma> arma)
    : Personaje(nombre, salud, std::move(arma)), experiencia(0), nivel(1) {}

void Jugador::ganarExperiencia(int exp) {
    experiencia += exp;
    if (experiencia >= nivel * 100) {
        subirNivel();
    }
}

void Jugador::subirNivel() {
    nivel++;
    saludMaxima += 20;
    salud = saludMaxima;
    experiencia = 0;
}

std::string Jugador::getTipo() const {
    return "Jugador";
}

int Jugador::getNivel() const {
    return nivel;
}

int Jugador::getExperiencia() const {
    return experiencia;
}