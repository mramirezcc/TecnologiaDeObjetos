#include "Celda.h"
#include "Personaje.h"
#include "Graficador.h"
#include <random>
#include <ctime>
#include <iostream>
#include <unistd.h>

int randomInt(int min, int max){
    static std::mt19937 generador(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generador);
}

int filas = 20;
int columnas = 20;
Celda** tab;

void inicializarTablero(){
    tab = new Celda*[filas];
    for(int i = 0; i < filas; i++){
        tab[i] = new Celda[columnas];
    }
}

void llenarTabla(){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            int aux = randomInt(1, 100);
            if(aux >= 75)
                tab[i][j].setOcupador(new Personaje());
        }
    }
}

void ciclo(){
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
                        int aux = randomInt(1, 4);
                        if(aux == 1 && i > 0)
                            newCel = &tab[i-1][j];
                        else if(aux == 2 && i < filas - 1)
                            newCel = &tab[i+1][j];
                        else if(aux == 3 && j > 0)
                            newCel = &tab[i][j-1];
                        else if(aux == 4 && j < columnas - 1)
                            newCel = &tab[i][j+1];
                        if(newCel == cel)
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

int main(){
    inicializarTablero();
    Graficador graf = Graficador(tab, filas, columnas);
    llenarTabla();

    while(true){
        ciclo();
        usleep(250000);
        graf.graficar();
    }
}
