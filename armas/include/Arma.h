#ifndef ARMA_H
#define ARMA_H

#include <string>

class Arma {
    protected:
        std::string nombre;
        int dmgBase;
        std::string elem;
        float probCrit;

    public:
        Arma(const std::string& nombre, int dmgBase, const std::string& elem = "Normal", float probCrit = 0.1f);
        virtual ~Arma() = default;

        virtual int calcularDmg() const;
        virtual std::string getTipo() const = 0;
        std::string getNombre() const;
        std::string getElem() const;
        bool esCritico() const;
};

#endif