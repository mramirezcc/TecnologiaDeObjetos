#include <iostream>
#include <memory>
#include "Espada.h"
#include "Arco.h"
#include "Hacha.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "SistemaCombate.h"

int main() {
    // Crear armas con diferentes elementos
    auto espadaFuego = std::make_unique<Espada>("Espada de Fuego", 25, "Fuego", 0.12f);
    auto arcoHielo = std::make_unique<Arco>("Arco de Hielo", 20, "Hielo", 0.18f);
    auto hachaElectrica = std::make_unique<Hacha>("Hacha Eléctrica", 30, "Eléctrico", 0.25f);
    
    // Crear jugador y enemigos
    Jugador heroe("Goblin Slayer", 100, std::move(espadaFuego));
    Enemigo goblin("Goblin", 50, std::make_unique<Arco>("Arco Simple", 15), "Goblin", 50);
    Enemigo orco("Orco Guerrero", 80, std::make_unique<Hacha>("Hacha de Batalla", 28), "Orco", 100);
    
    // Mostrar estado inicial
    SistemaCombate::mostrarEstado(heroe);
    SistemaCombate::mostrarEstado(goblin);
    
    // Combate contra goblin
    SistemaCombate::iniciarCombate(heroe, goblin);
    
    if (heroe.estaVivo()) {
        std::cout << "\nEl héroe ha ganado experiencia! Nivel: " << heroe.getNivel() << std::endl;
        
        // Cambiar arma del jugador
        heroe.cambiarArma(std::move(arcoHielo));
        std::cout << "El héroe ahora usa: " << heroe.getTipoArma() << std::endl;
        
        // Combate contra orco
        SistemaCombate::iniciarCombate(heroe, orco);
    }
    
    return 0;
}