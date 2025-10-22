#ifndef TAREA_SIMPLE_H
#define TAREA_SIMPLE_H

#include "TareaBase.h"
#include <memory>

class TareaSimple : public TareaBase {
public:
    TareaSimple(const std::string& desc = "", int prio = 1);
    
    // covarianza
    TareaSimple* clonar() const override;
    
    // version con unique_ptr
    std::unique_ptr<TareaBase> clonarUnique() const override;
    
    void mostrarInfo() const override;
    
    // sobrecarga de operadores
    TareaSimple operator+(const TareaSimple& otra) const;
};

#endif