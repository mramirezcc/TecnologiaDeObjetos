#include <iostream>
#include <vector>
#include "cliente.h"
#include "producto.h"
#include "detallePedido.h"
#include "pedido.h"

using namespace std;

vector<Cliente> clientes;
vector<Producto> productos;
vector<Pedido> pedidos;

int main(){
    int opcion;
    do{
        cout << "===== MENU CAFETERIA =====" << endl;
        cout << "1. Registrar Cliente      " << endl;
        cout << "2. Registrar Producto     " << endl;
        cout << "3. Tomar Pedido           " << endl;
        cout << "4. Mostrar Pedidos        " << endl;
        cout << "5. Salir                  " << endl;
        cin >> opcion;
        cin.ignore();

        if(opcion == 1){
            //------------registrar Cliente---------
            int id;
            string nombre, telefono, direccion;
            cout << "Ingrese ID del cliente : "; cin >> id; cin.ignore();
            cout << "Ingrese nombre completo: "; getline(cin, nombre);
            cout << "Ingrese telefono:  ";       getline(cin, telefono);
            cout << "Ingrese direccion: ";       getline(cin, direccion);

            Cliente nuevo(id, nombre, telefono, direccion);
            clientes.push_back(nuevo);

            cout << "--Cliente registrado--" << endl;

        } else if(opcion == 2){
            //-----------registrar Producto---------
            int id, stock;
            string nombre, descripcion;
            double precio;

            cout << "Ingrese ID del producto: "; cin >> id; cin.ignore();
            cout << "Ingrese nombre: ";          getline(cin, nombre);
            cout << "Ingrese descripcion: ";     getline(cin, descripcion);
            cout << "Ingrese precio: ";          cin >> precio;
            cout << "Ingrese stock: ";           cin >> stock;

            Producto nuevo(id, nombre, descripcion, precio, stock);
            productos.push_back(nuevo);

            cout << "Producto registrado correctamente!" << endl;

        } else if(opcion == 3){
            // Tomar Pedido
            if(clientes.empty() || productos.empty()){
                cout << "Debe haber al menos un cliente y un producto registrado." << endl;
                continue;
            }

            int idPedido;
            string fecha;
            cout << "Ingrese ID del pedido: ";
            cin >> idPedido; cin.ignore();
            cout << "Ingrese fecha (dd/mm/aaaa): ";
            getline(cin, fecha);

            // Seleccionar cliente
            cout << "Seleccione cliente por ID:" << endl;
            for(size_t i = 0; i < clientes.size(); i++){
                cout << clientes[i].getId() << " - " << clientes[i].getFullName() << endl;
            }
            int idCliente;
            cin >> idCliente;
            Cliente clienteSeleccionado;
            for(size_t i = 0; i < clientes.size(); i++){
                if(clientes[i].getId() == idCliente){
                    clienteSeleccionado = clientes[i];
                    break;
                }
            }

            Pedido pedido(idPedido, clienteSeleccionado, fecha);

            // Agregar productos al pedido
            char agregarMas;
            do{
                cout << "Seleccione producto por ID:" << endl;
                for(size_t i = 0; i < productos.size(); i++){
                    cout << productos[i].getId() << " - " << productos[i].getName() 
                         << " ($" << productos[i].getPrice() << ")" << endl;
                }
                int idProd, cantidad;
                cin >> idProd;
                cout << "Ingrese cantidad: ";
                cin >> cantidad;

                for(size_t i = 0; i < productos.size(); i++){
                    if(productos[i].getId() == idProd){
                        if(cantidad <= productos[i].getStock()){
                            DetallePedido detalle(productos[i], cantidad);
                            pedido.agregarDetalle(detalle);
                            productos[i].setStock(productos[i].getStock() - cantidad);
                        } else{
                            cout << "Stock insuficiente!" << endl;
                        }
                    }
                }

                cout << "¿Desea agregar otro producto? (s/n): ";
                cin >> agregarMas;
            } while(agregarMas == 's' || agregarMas == 'S');

            pedidos.push_back(pedido);
            cout << "Pedido registrado correctamente!" << endl;

        } else if(opcion == 4){
            // Mostrar Pedidos
            if(pedidos.empty()){
                cout << "No hay pedidos registrados." << endl;
            } else{
                for(size_t i = 0; i < pedidos.size(); i++){
                    pedidos[i].mostrarInfo();
                    cout << "-----------------------------" << endl;
                }
            }
        }

    } while(opcion != 5);

    cout << "Saliendo del sistema..." << endl;
    return 0;
}
