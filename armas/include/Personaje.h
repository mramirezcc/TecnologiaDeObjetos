#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <memory>
#include "Arma.h"

class Personaje {
    protected:
        std::string nombre;
        int salud;
        int saludMaxima;
        std::unique_ptr<Arma> arma;
    
    public:
        Personaje(const std::string& nombre, int salud, std::unique_ptr<Arma> arma);
        virtual ~Personaje() = default;
        
        virtual void recibirDanio(int danio);
        virtual int atacar() const;
        bool estaVivo() const;
        std::string getNombre() const;
        int getSalud() const;
        std::string getTipoArma() const;
        void cambiarArma(std::unique_ptr<Arma> nuevaArma);
        virtual std::string getTipo() const = 0;
};

#endif