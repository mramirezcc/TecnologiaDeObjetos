#include "cliente.h"
#include <iostream>
using namespace std;
//Constructores
Cliente::Cliente(){
    this->id = 0;
    this->fullName = "";
    this->numeroTelefono = "";
    this->direccion = "";
}
Cliente::Cliente(int id, string fullName, string numeroTelefono, string direccion){
    this->id = id;
    this->fullName = fullName;
    this->numeroTelefono = numeroTelefono;
    this->direccion = direccion;
}
//Setters
void Cliente::setId(int id){this->id = id;}
void Cliente::setFullName(string fullName){this->fullName = fullName;}
void Cliente::setNumeroTelefono(string numeroTelefono){this->numeroTelefono = numeroTelefono;}
void Cliente::setDireccion(string direccion){this->direccion = direccion;}
//Getters
int Cliente::getId(){return this->id;}
string Cliente::getFullName(){return this->fullName;}
string Cliente::getNumeroTelefono(){return this->numeroTelefono;}
string Cliente::getDireccion(){return this->direccion;}

//Metodos
void Cliente::mostrarInfo(){
    cout << "ID: " << this->id << endl;
    cout << "Nombre Completo: " << this->fullName << endl;
    cout << "Numero de Telefono: " << this->numeroTelefono << endl;
    cout << "Direccion: " << this->direccion << endl;
}