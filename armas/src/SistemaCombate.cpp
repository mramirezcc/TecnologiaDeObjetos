#include "SistemaCombate.h"
#include <iostream>

void SistemaCombate::iniciarCombate(Jugador& jugador, Enemigo& enemigo) {
    std::cout << "=== COMBATE INICIADO ===" << std::endl;
    std::cout << jugador.getNombre() << " (Nivel " << jugador.getNivel() << ") vs " 
              << enemigo.getNombre() << " (" << enemigo.getTipoEnemigo() << ")" << std::endl;
    
    while (jugador.estaVivo() && enemigo.estaVivo()) {
        // Turno del jugador
        int danioJugador = jugador.atacar();
        enemigo.recibirDanio(danioJugador);
        std::cout << jugador.getNombre() << " ataca con " << jugador.getTipoArma() 
                  << " y causa " << danioJugador << " de daño!" << std::endl;
        
        if (!enemigo.estaVivo()) {
            std::cout << enemigo.getNombre() << " ha sido derrotado!" << std::endl;
            jugador.ganarExperiencia(enemigo.getRecompensaExperiencia());
            break;
        }
        
        // Turno del enemigo
        int danioEnemigo = enemigo.atacar();
        jugador.recibirDanio(danioEnemigo);
        std::cout << enemigo.getNombre() << " ataca con " << enemigo.getTipoArma() 
                  << " y causa " << danioEnemigo << " de daño!" << std::endl;
        
        if (!jugador.estaVivo()) {
            std::cout << jugador.getNombre() << " ha sido derrotado!" << std::endl;
            break;
        }
        
        mostrarEstado(jugador);
        mostrarEstado(enemigo);
        std::cout << "------------------------" << std::endl;
    }
    
    std::cout << "=== COMBATE FINALIZADO ===" << std::endl;
}

void SistemaCombate::mostrarEstado(const Personaje& personaje) {
    std::cout << personaje.getTipo() << " " << personaje.getNombre() 
              << " - Salud: " << personaje.getSalud() 
              << " - Arma: " << personaje.getTipoArma() << std::endl;
}