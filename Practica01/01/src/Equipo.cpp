#include "Equipo.h"
#include <iostream>

std::vector<Equipo*> Equipo::equipos = std::vector<Equipo*>();

Equipo::Equipo(){
    equipos.push_back(this);
}

Equipo::~Equipo(){
    for(int i = 0; i < personajes.size(); i++){
        delete personajes[i];
    }
}

void Equipo::showEquipos(){
    std::cout << "Numero de equipos: " << equipos.size() << "\n";
    for(int i = 0; i < equipos.size(); i++){
        std::cout << "Equipo " << i+1 << " tiene " << equipos[i]->personajes.size() << " personajes.\n";
    }
}

