#ifndef ARMA_H
#define ARMA_H

#include <string>

class Arma {
    protected:
        std::string nombre;
        int danioBase;
        std::string elemento;
        float probabilidadCritico;
    
    public:
        Arma(const std::string& nombre, int danioBase, const std::string& elemento = "Normal", float probCritico = 0.1f);
        virtual ~Arma() = default;
        
        virtual int calcularDanio() const;
        virtual std::string getTipo() const = 0;
        std::string getNombre() const;
        std::string getElemento() const;
        bool esCritico() const;
};

#endif