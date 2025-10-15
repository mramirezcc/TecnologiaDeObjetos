#ifndef TAREA_H
#define TAREA_H

#include <string>
#include <algorithm>

class Tarea {
private:
    std::string descripcion;
    bool completada;
    int prioridad;

public:
    Tarea(const std::string& desc = "", int prio = 1);
    
    inline std::string getDescripcion() const { return descripcion; }
    inline bool estaCompletada() const { return completada; }
    inline int getPrioridad() const { return prioridad; }
    inline void marcarCompletada() { completada = true; }
    
    bool operator==(const Tarea& otra) const;
    Tarea operator+(const Tarea& otra) const;
    
    friend void intercambiarTareas(Tarea& t1, Tarea& t2);
    
    // Template DEFINIDO en el .h
    template<typename Func>
    void modificarDescripcion(Func modificador) {
        descripcion = modificador(descripcion);
    }
};

#endif