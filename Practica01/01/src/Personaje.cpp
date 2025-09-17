#include "Personaje.h"
#include <string>

const std::string Personaje::color[] = {"\e[0;34m", "\e[0;37m", "\e[0;31m", "\e[0;32m"};

void Personaje::setEstado(int estado){
    this->estado = estado;
}

void Personaje::setVida(int vida){
    this->vida = vida;
}

void Personaje::setDefensa(int defensa){
    this->defensa = defensa;
}

void Personaje::setAtaque(int ataque){
    this->ataque = ataque;
}

void Personaje::setObjetivo(Personaje* objetivo){
    this->objetivo = objetivo;
}

std::string Personaje::getIcono(){
    /*std::string barra = "█";
    float porcentaje = this->vida / this->vidaMax;
    if(porcentaje < 0.75)
        barra = "▓";
    if(porcentaje < 0.5)
        barra = "▒";
    if(porcentaje < 0.25)
        barra = "░";*/
    return "" + this->color[this->estado] + this->icono + "\e[0;37m";
}

void Personaje::setIcono(std::string){
    this->icono = icono;
}

int Personaje::getEstado(){
    return this->estado;
}

int Personaje::getVida(){
    return this->vida;
}

int Personaje::getDefensa(){
    return this->defensa;
}

int Personaje::getAtaque(){
    return this->ataque;
}

Personaje* Personaje::getObjetivo(){
    return this->objetivo;
}

Personaje::Personaje(std::string icono, int estado, int vida, int defensa, int ataque){
    this->icono = icono;
    this->estado = estado;
    this->vida = vida;
    this->vidaMax = vida;
    this->defensa = defensa;
    this->defensaMax = defensa;
    this->ataque = ataque;
}

Personaje::Personaje() :
    Personaje("ඞ", 1, 20, 50, 10){}

void Personaje::atacar(){
    this->objetivo->recibirAtaque(this->ataque);
}

void Personaje::recibirAtaque(int ataque){
    if(this->defensa > 0){
        if(this->defensa <= ataque)
            this->defensa = 0;
        else
            this->defensa -= ataque;
    }else{
        if(this->vida <= ataque){
            this->vida = 0;
            this->estado = 0;
            this->icono = " ";
        }
        else
            this->vida -= ataque;
    }
}

void Personaje::curar(){
    if(this->vida < this->vidaMax)
        this->vida += 5;
    if(vidaCompleta())
        setEstado(1);
}

bool Personaje::vidaCompleta(){
    return this->vida >= this->vidaMax; 
}

void Personaje::reposar(){
    if(this->defensa < this->defensaMax)
        this->defensa += 1;
}

void Personaje::setVidaMax(int vidaMax){
    this->vidaMax = vidaMax;
}

void Personaje::setDefensaMax(int defensaMax){
    this->defensaMax = defensaMax;
}
