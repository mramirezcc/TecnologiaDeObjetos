#include "producto.h"
#include <iostream>

using namespace std;

//Constructores
Producto::Producto(){
    this->id = 0;
    this->name = "";
    this->description = "";
    this->price = 0.0;
    this->stock = 0;
}
Producto::Producto(int id, string name, string description, double price, int stock){
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
    this->stock = stock;
}
//Setters
void Producto::setId(int id){this->id = id;}
void Producto::setName(string name){this->name = name;}
void Producto::setDescription(string description){this->description = description;}
void Producto::setPrice(double price){this->price = price;}
void Producto::setStock(int stock){this->stock = stock;}
//Getters
int Producto::getId(){return this->id;}
string Producto::getName(){return this->name;}
string Producto::getDescription(){return this->description;}
double Producto::getPrice(){return this->price;}
int Producto::getStock(){return this->stock;}
//Metodos
void Producto::mostrarInfo(){
    cout << "ID: " << this->id << endl;
    cout << "Nombre: " << this->name << endl;
    cout << "Descripcion: " << this->description << endl;
    cout << "Precio: " << this->price << endl;
    cout << "Stock: " << this->stock << endl;
}