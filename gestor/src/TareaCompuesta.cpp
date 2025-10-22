#include "TareaCompuesta.h"

TareaCompuesta::TareaCompuesta(const std::string& desc, int prio) 
    : TareaBase(desc, prio) {}

// covarianza
TareaCompuesta* TareaCompuesta::clonar() const {
    auto copia = new TareaCompuesta(descripcion, prioridad);
    for (const auto& subtarea : subtareas) {
        copia->agregarSubtarea(*subtarea);
    }
    return copia;
}

// sin covarianza
std::unique_ptr<TareaBase> TareaCompuesta::clonarUnique() const {
    auto copia = std::make_unique<TareaCompuesta>(descripcion, prioridad);
    for (const auto& subtarea : subtareas) {
        copia->agregarSubtarea(*subtarea);
    }
    return copia;
}

void TareaCompuesta::mostrarInfo() const {
    std::cout << "Tarea Compuesta: " << descripcion 
              << " [P:" << prioridad << "]"
              << " - " << subtareas.size() << " subtareas" 
              << (completada ? " ✓" : " ✗") << std::endl;
}

// contravarianza
void TareaCompuesta::agregarSubtarea(const TareaBase& tarea) {
    subtareas.push_back(std::make_unique<TareaSimple>(
        tarea.getDescripcion(), tarea.getPrioridad()));
}

template<typename Func>
void TareaCompuesta::paraCadaSubtarea(Func procesador) {
    for (auto& subtarea : subtareas) {
        procesador(*subtarea);
    }
}