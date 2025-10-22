#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include "TareaBase.h"
#include "TareaSimple.h"
#include "TareaCompuesta.h"
#include <vector>
#include <memory>

class GestorTareas {
    private:
        std::vector<std::unique_ptr<TareaBase>> tareas;

    public:
        // funciones inline
        inline int cantidadTareas() const { return tareas.size(); }
        inline bool estaVacio() const { return tareas.empty(); }

        void agregarTarea(std::unique_ptr<TareaBase> tarea);
        void agregarTarea(TareaBase* tarea);

        template<typename T>
        void agregarTareaDerivada(std::unique_ptr<T> tarea);

        void mostrarTareas() const;

        // templates
        template<typename Func>
        void forEachTarea(Func accion) {
            for (auto& tarea : tareas) {
                accion(*tarea);
            }
        }

        // contravarianza
        template<typename Func>
        void procesarTodasTareas(Func procesador) {
            for (auto& tarea : tareas) {
                procesador(*tarea);
            }
        }
};

#endif