#ifndef TAREA_BASE_H
#define TAREA_BASE_H

#include <string>
#include <memory>
#include <iostream>

class TareaBase {
    protected:
        std::string descripcion;
        bool completada;
        int prioridad;

    public:
        TareaBase(const std::string& desc = "", int prio = 1);
        virtual ~TareaBase() = default;

        // Funciones inline constantes
        inline std::string getDescripcion() const { return descripcion; }
        inline bool estaCompletada() const { return completada; }
        inline int getPrioridad() const { return prioridad; }
        inline void marcarCompletada() { completada = true; }

        // Covarianza obligando a override
        virtual TareaBase* clonar() const = 0;
        virtual void mostrarInfo() const = 0;

        // sin covarianza
        virtual std::unique_ptr<TareaBase> clonarUnique() const = 0;
};

#endif