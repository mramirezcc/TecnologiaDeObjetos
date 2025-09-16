#include "Graficador.h"
#include <string>
#include <iostream>

Graficador::Graficador(Celda** tab, int filas, int columnas){
    this->tablero = tab;
    this->filas = filas;
    this->columnas = columnas;
}

void Graficador::graficar(){
    std::string res = "╔═";

    for(int i = 0; i < this->columnas; i++){
        res += "══";
    }
    res += "╗\n";

    for(int i = 0; i < this->filas; i++){
        res += "║";
        for(int j = 0; j < this->columnas; j++){
            res += " ";
            if(this->tablero[i][j].getTipo() == 1){
                res += "\e[0;34mX\e[0;37m";
            }else if(this->tablero[i][j].getOcupador() != nullptr)
                res += this->tablero[i][j].getOcupador()->getIcono();
            else
                res += " ";
            //res += " ";
        }
        res += " ║\n";
    }

    res += "╚═";
    for(int i = 0; i < this->columnas; i++){
        res += "══";
    }
    res += "╝\n";

    std::cout << res;
}