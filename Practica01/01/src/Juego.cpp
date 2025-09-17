#include "Celda.h"
#include "Personaje.h"
#include "Graficador.h"
#include "Juego.h"
#include <random>
#include <ctime>
#include <iostream>

Juego::Juego(Celda** tab, int filas, int columnas){
    this->tab = tab;
    this->filas = filas;
    this->columnas = columnas;
    this->inicializarTablero();
    this->llenarTabla();
}

int Juego::randomInt(int min, int max){
    static std::mt19937 generador(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generador);
}


void Juego::inicializarTablero(){
    // this->tab = new Celda*[this->filas];
    for(int i = 0; i < this->filas; i++){
        this->tab[i] = new Celda[this->columnas];
    }
}

void Juego::llenarTabla(){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            int aux = randomInt(1, 100);
            if(aux >= 90){
                char simboloAscii = static_cast<char>(randomInt(48, 126));
                std::string iconoStr(1, simboloAscii);  // Convertir char a string de 1 carácter

                Personaje* newPer = new Personaje(iconoStr, 1, randomInt(50, 150), randomInt(10, 50), randomInt(5, 30));
                tab[i][j].setOcupador(newPer);
            }
        }
    }
}

void Juego::ciclo(){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            Celda* cel = &tab[i][j];
            if(cel->getOcupador() == nullptr)
                continue;
            else{
                Personaje* per = cel->getOcupador();
                switch(per->getEstado()){
                    //Muerto
                    case 0:
                        break;
                    //Reposo
                    case 1:{
                        per->reposar();
                        // verificacion de movimiento
                        Celda* newCel = cel;
                        int aux = randomInt(1, 8);
                        if(aux >= 8)
                            newCel = cel;
                        else if(aux == 1 && i > 0)
                            newCel = &tab[i-1][j];
                        else if(aux == 2 && i < filas - 1)
                            newCel = &tab[i+1][j];
                        else if(aux == 3 && j > 0)
                            newCel = &tab[i][j-1];
                        else if(aux == 4 && j < columnas - 1)
                            newCel = &tab[i][j+1];
                        if(newCel == cel || newCel->getTipo() == 1)
                            break;
                        //movimiento
                        if(newCel->getOcupador() == nullptr || newCel->getOcupador()->getEstado() == 0){
                            cel->liberar();
                            newCel->liberar();
                            newCel->setOcupador(per);
                        }else{
                            Personaje* per2 = newCel->getOcupador();
                            per->setObjetivo(per2);
                            per->setEstado(2);
                            per2->setObjetivo(per);
                            per2->setEstado(2);
                        }
                        break;
                    }
                    // ataque
                    case 2:{
                        per->atacar();
                        if(per->getObjetivo()->getEstado() == 0){
                            per->setObjetivo(nullptr);
                            per->setEstado(3);
                        }
                        break;
                    }
                    // curacion
                    case 3:{
                        per->curar();
                        break;
                    }
                    default:{
                        per->recibirAtaque(200);
                        break;
                    }
                }
            }
        }
    }
}

void Juego::recortarZona(int contador, int numCiclos){

    int aux = (contador / numCiclos) - 1;
    // horizontal
    for(int i = aux; i < filas - aux; i++){
        tab[aux][i].setTipo(1);
        tab[filas - aux - 1][i].setTipo(1);
    }
    // vertical
    for(int i = aux; i < columnas - aux; i++){
        tab[i][aux].setTipo(1);
        tab[i][filas - aux - 1].setTipo(1);
    }
}