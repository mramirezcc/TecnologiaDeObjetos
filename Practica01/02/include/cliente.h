#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente{
    private:
    int id;
    string fullName;
    string numeroTelefono;
    string direccion;
    
    public:
    //Constructores
    Cliente();
    Cliente(int id, string fullName, string numeroTelefono, string direccion);
    //Setters
    void setId(int id);
    void setFullName(string fullName);
    void setNumeroTelefono(string numeroTelefono);
    void setDireccion(string direccion);
    //Getters
    int getId();
    string getFullName();
    string getNumeroTelefono();
    string getDireccion();
    
    //Metodos
    void mostrarInfo();    
};

#endif