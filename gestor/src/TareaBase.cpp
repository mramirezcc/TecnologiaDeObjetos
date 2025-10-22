#include "TareaBase.h"

TareaBase::TareaBase(const std::string& desc, int prio) 
    : descripcion(desc), completada(false), prioridad(prio) {}