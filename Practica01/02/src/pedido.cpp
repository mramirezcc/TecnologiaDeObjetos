#include "pedido.h"
#include <iostream>
using namespace std;

//Constructores
Pedido::Pedido(){
    this->idPedido = 0;
    this->cliente = Cliente();
    this->fecha = "";
    this->total = 0.0;
}
Pedido::Pedido(int idPedido, Cliente cliente, string fecha){
    this->idPedido = idPedido;
    this->cliente = cliente;
    this->fecha = fecha;
    this->total = 0.0;
}

//Setters
void Pedido::setIdPedido(int idPedido){this->idPedido = idPedido;}
void Pedido::setCliente(Cliente cliente){this->cliente = cliente;}
void Pedido::setFecha(string fecha){this->fecha = fecha;}

//Getters
int Pedido::getIdPedido(){return this->idPedido;}
Cliente Pedido::getCliente(){return this->cliente;}
string Pedido::getFecha(){return this->fecha;}
double Pedido::getTotal(){return this->total;}

//Metodos
void Pedido::agregarDetalle(DetallePedido detalle){
    this->detalles.push_back(detalle);
    this->calcularTotal();
}
void Pedido::calcularTotal(){
    this->total = 0.0;
    for(size_t i = 0; i < this->detalles.size(); i++){
        this->total += this->detalles[i].getSubtotal();
    }
}
void Pedido::mostrarInfo(){
    cout << "Pedido ID: " << this->idPedido << endl;
    cout << "Fecha: " << this->fecha << endl;
    cout << "Cliente: " << this->cliente.getFullName() << endl;
    cout << "Detalles:" << endl;
    for(size_t i = 0; i < this->detalles.size(); i++){
        this->detalles[i].mostrarInfo();
    }
    cout << "Total: " << this->total << endl;
}
