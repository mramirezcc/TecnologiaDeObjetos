#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto{
    private:
    int id;
    string name;
    string description;
    double price;
    int stock;


    public:
    //Constructores
    Producto();
    Producto(int id, string name, string description, double price, int stock);
    
    //Setters
    void setId(int id);
    void setName(string name);
    void setDescription(string description);
    void setPrice(double price);
    void setStock(int stock);
    
    //Getters
    int getId();
    string getName();
    string getDescription();
    double getPrice();
    int getStock();
    
    //Metodos
    void mostrarInfo();    
};

#endif