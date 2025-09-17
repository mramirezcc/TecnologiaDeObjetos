#include "detallePedido.h"
#include <iostream>
using namespace std;

//Constructores
DetallePedido::DetallePedido(){
    this->producto = Producto();
    this->cantidad = 0;
    this->subtotal = 0.0;
}
DetallePedido::DetallePedido(Producto producto, int cantidad){
    this->producto = producto;
    this->cantidad = cantidad;
    this->subtotal = producto.getPrice() * cantidad;
}

//Setters
void DetallePedido::setProducto(Producto producto){
    this->producto = producto;
    this->subtotal = this->producto.getPrice() * this->cantidad;
}
void DetallePedido::setCantidad(int cantidad){
    this->cantidad = cantidad;
    this->subtotal = this->producto.getPrice() * this->cantidad;
}

//Getters
Producto DetallePedido::getProducto(){return this->producto;}
int DetallePedido::getCantidad(){return this->cantidad;}
double DetallePedido::getSubtotal(){return this->subtotal;}

//Metodos
void DetallePedido::calcularSubtotal(){
    this->subtotal = this->producto.getPrice() * this->cantidad;
}
void DetallePedido::mostrarInfo(){
    cout << "Producto: " << this->producto.getName() 
         << " | Cantidad: " << this->cantidad 
         << " | Subtotal: " << this->subtotal << endl;
}
