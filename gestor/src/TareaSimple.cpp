#include "TareaSimple.h"

TareaSimple::TareaSimple(const std::string& desc, int prio) 
    : TareaBase(desc, prio) {}

// covarianza
TareaSimple* TareaSimple::clonar() const {
    return new TareaSimple(*this);
}

// sin covarianza
std::unique_ptr<TareaBase> TareaSimple::clonarUnique() const {
    return std::make_unique<TareaSimple>(*this);
}

void TareaSimple::mostrarInfo() const {
    std::cout << "Tarea Simple: " << descripcion 
              << " [P:" << prioridad << "]" 
              << (completada ? " ✓" : " ✗") << std::endl;
}

TareaSimple TareaSimple::operator+(const TareaSimple& otra) const {
    std::string nuevaDesc = descripcion + " + " + otra.descripcion;
    int nuevaPrio = std::max(prioridad, otra.prioridad);
    return TareaSimple(nuevaDesc, nuevaPrio);
}