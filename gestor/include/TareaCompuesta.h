#ifndef TAREA_COMPUESTA_H
#define TAREA_COMPUESTA_H

#include "TareaBase.h"
#include "TareaSimple.h"
#include <vector>
#include <memory>

class TareaCompuesta : public TareaBase {
    private:
        std::vector<std::unique_ptr<TareaBase>> subtareas;
    
    public:
        TareaCompuesta(const std::string& desc = "", int prio = 1);
        
        // COVARIANZA: Puntero raw
        TareaCompuesta* clonar() const override;
        
        // Versión con unique_ptr
        std::unique_ptr<TareaBase> clonarUnique() const override;
        
        void mostrarInfo() const override;
        
        // CONTRAVARIANZA
        void agregarSubtarea(const TareaBase& tarea);
        
        template<typename Func>
        void paraCadaSubtarea(Func procesador);
};

#endif