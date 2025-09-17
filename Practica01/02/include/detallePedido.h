#ifndef DETALLEPEDIDO_H
#define DETALLEPEDIDO_H

#include "producto.h"
#include <string>
using namespace std;

class DetallePedido {
    private:
        Producto producto;
        int cantidad;
        double subtotal;

    public:
        // Constructores
        DetallePedido();
        DetallePedido(Producto producto, int cantidad);

        // Setters
        void setProducto(Producto producto);
        void setCantidad(int cantidad);

        // Getters
        Producto getProducto();
        int getCantidad();
        double getSubtotal();

        // Métodos
        void calcularSubtotal();
        void mostrarInfo();
};

#endif
