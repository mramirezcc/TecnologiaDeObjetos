#include "Enemigo.h"

Enemigo::Enemigo(const std::string& nombre, int salud, std::unique_ptr<Arma> arma, 
                 const std::string& tipoEnemigo, int recompensaExp)
    : Personaje(nombre, salud, std::move(arma)), tipoEnemigo(tipoEnemigo), recompensaExperiencia(recompensaExp) {}

std::string Enemigo::getTipo() const {
    return "Enemigo";
}

std::string Enemigo::getTipoEnemigo() const {
    return tipoEnemigo;
}

int Enemigo::getRecompensaExperiencia() const {
    return recompensaExperiencia;
}