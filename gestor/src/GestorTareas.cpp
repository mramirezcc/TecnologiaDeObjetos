#include "GestorTareas.h"
#include <iostream>

void GestorTareas::agregarTarea(std::unique_ptr<TareaBase> tarea) {
    tareas.push_back(std::move(tarea));
}

void GestorTareas::agregarTarea(TareaBase* tarea) {
    tareas.emplace_back(tarea);
}

template<typename T>
void GestorTareas::agregarTareaDerivada(std::unique_ptr<T> tarea) {
    static_assert(std::is_base_of_v<TareaBase, T>, "T debe derivar de TareaBase");
    tareas.push_back(std::move(tarea));
}

void GestorTareas::mostrarTareas() const {
    std::cout << "=== LISTA DE TAREAS ===" << std::endl;
    for (size_t i = 0; i < tareas.size(); ++i) {
        std::cout << i + 1 << ". ";
        tareas[i]->mostrarInfo();
    }
    std::cout << "Total: " << cantidadTareas() << " tareas" << std::endl;
}