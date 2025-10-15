#include "GestorTareas.h"

void GestorTareas::agregarTarea(const Tarea& tarea) {
    tareas.push_back(tarea);
}

void GestorTareas::eliminarTarea(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice) < tareas.size()) {
        tareas.erase(tareas.begin() + indice);
    }
}

void GestorTareas::mostrarTareas() const {
    std::cout << "=== LISTA DE TAREAS ===" << std::endl;
    for (size_t i = 0; i < tareas.size(); ++i) {
        std::cout << i + 1 << ". " << tareas[i].getDescripcion()
                  << " [Prioridad: " << tareas[i].getPrioridad()
                  << "] - " << (tareas[i].estaCompletada() ? "COMPLETADA" : "PENDIENTE")
                  << std::endl;
    }
    std::cout << "Total: " << cantidadTareas() << " tareas" << std::endl;
}

void fusionarGestores(const GestorTareas& g1, const GestorTareas& g2, GestorTareas& resultado) {
    for (const auto& tarea : g1.tareas) {
        resultado.agregarTarea(tarea);
    }
    for (const auto& tarea : g2.tareas) {
        resultado.agregarTarea(tarea);
    }
}