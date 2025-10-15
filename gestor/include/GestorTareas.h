#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include "Tarea.h"
#include <vector>
#include <iostream>

class GestorTareas {
    private:
        std::vector<Tarea> tareas;

    public:
        inline int cantidadTareas() const { return tareas.size(); }
        inline bool estaVacio() const { return tareas.empty(); }

        void agregarTarea(const Tarea& tarea);
        void eliminarTarea(int indice);
        void mostrarTareas() const;

        // templates
        template<typename Func>
        std::vector<Tarea> filtrarTareas(Func criterio) const {
            std::vector<Tarea> resultado;
            for (const auto& tarea : tareas) {
                if (criterio(tarea)) {
                    resultado.push_back(tarea);
                }
            }
            return resultado;
        }

        template<typename Func>
        void forEachTarea(Func accion) {
            for (auto& tarea : tareas) {
                accion(tarea);
            }
        }

        friend void fusionarGestores(const GestorTareas& g1, const GestorTareas& g2, GestorTareas& resultado);
};

#endif