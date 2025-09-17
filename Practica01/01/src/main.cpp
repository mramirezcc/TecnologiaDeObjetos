#include "Juego.h"
#include "Graficador.h"
#include <iostream>
#include <unistd.h>

int main(){
    int filas = 20;
    int columnas = 20;
    Celda** tab = new Celda*[filas];

    Juego j = Juego(tab, filas, columnas);
    Graficador graf = Graficador(tab, filas, columnas);

    int contador = 0;
    int numCiclos = 30;
    while(contador/numCiclos <= filas/2 || contador/numCiclos <= columnas/2){
        if(contador > 0 && contador % numCiclos == 0){
            j.recortarZona(contador, numCiclos);
        }
        j.ciclo();
        graf.graficar();
        contador++;
        usleep(125000);
    }
    std::cout << "Simulacion terminada!\n";
}
