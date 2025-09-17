#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje{
    private:
        static const std::string color[];
        std::string icono;
        // 0 - muerto
        // 1 - reposo
        // 2 - ataque
        // 3 - curacion

        int estado;
        int vida;
        int vidaMax;
        int defensa;
        int defensaMax;
        int ataque;
        Personaje* objetivo;

    protected:
        void setVidaMax(int vidaMax);
        void setDefensaMax(int defensaMax);

    public:
        void setVida(int vida);
        void setDefensa(int defensa);
        void setAtaque(int ataque);
        void setEstado(int estado);
        void setObjetivo(Personaje* objetivo);
        void setIcono(std::string);

        std::string getIcono();
        int getEstado();
        int getVida();
        int getDefensa();
        int getAtaque();
        Personaje* getObjetivo();

        Personaje(std::string icono, int estado, int vida, int defensa, int ataque);
        Personaje();

        void atacar();
        void recibirAtaque(int ataque);
        void curar();
        void reposar();
        bool vidaCompleta();
};

#endif