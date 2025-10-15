#include "Tarea.h"

Tarea::Tarea(const std::string& desc, int prio) 
    : descripcion(desc), completada(false), prioridad(prio) {}

bool Tarea::operator==(const Tarea& otra) const {
    return (descripcion == otra.descripcion) && 
           (completada == otra.completada) && 
           (prioridad == otra.prioridad);
}

Tarea Tarea::operator+(const Tarea& otra) const {
    std::string nuevaDesc = descripcion + " + " + otra.descripcion;
    int nuevaPrio = std::max(prioridad, otra.prioridad);
    return Tarea(nuevaDesc, nuevaPrio);
}

void intercambiarTareas(Tarea& t1, Tarea& t2) {
    std::swap(t1.descripcion, t2.descripcion);
    std::swap(t1.completada, t2.completada);
    std::swap(t1.prioridad, t2.prioridad);
}