#ifndef PEDIDO_H
#define PEDIDO_H

#include "cliente.h"
#include "detallePedido.h"
#include <vector>
#include <string>
using namespace std;

class Pedido {
    private:
        int idPedido;
        Cliente cliente;
        string fecha;
        vector<DetallePedido> detalles;
        double total;

    public:
        // Constructores
        Pedido();
        Pedido(int idPedido, Cliente cliente, string fecha);

        // Setters
        void setIdPedido(int idPedido);
        void setCliente(Cliente cliente);
        void setFecha(string fecha);

        // Getters
        int getIdPedido();
        Cliente getCliente();
        string getFecha();
        double getTotal();

        // Métodos
        void agregarDetalle(DetallePedido detalle);
        void calcularTotal();
        void mostrarInfo();
};

#endif
