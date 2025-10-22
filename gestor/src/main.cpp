#include <iostream>
#include "GestorTareas.h"

using namespace std;

int main() {
    cout << "=== GESTOR DE TAREAS ===" << endl;
    
    GestorTareas gestor;
    
    // covarianza
    cout << "\n1. COVARIANZA:" << endl;
    
    TareaSimple tareaSimple("Tarea Simple", 2);
    TareaCompuesta tareaCompuesta("Tarea Compuesta", 1);
    
    // clonacion de tareas
    TareaSimple* clonSimple = tareaSimple.clonar();      // TareaSimple*
    TareaCompuesta* clonCompuesta = tareaCompuesta.clonar(); // TareaCompuesta*
    
    cout << "Clon simple: ";
    clonSimple->mostrarInfo();
    
    cout << "Clon compuesta: ";
    clonCompuesta->mostrarInfo();
    
    // agregar al gestor
    gestor.agregarTarea(clonSimple);
    gestor.agregarTarea(clonCompuesta);
    
    // contravarianza
    cout << "\n2. CONTRAVARIANZA:" << endl;
    
    TareaSimple subtarea("Subtarea", 2);
    tareaCompuesta.agregarSubtarea(subtarea); // acepta TareaSimple donde espera TareaBase&
    
    // contravarianza con lambda
    gestor.procesarTodasTareas([](TareaBase& tarea) {
        cout << "Procesando: " << tarea.getDescripcion() << endl;
    });
    
    // lambda y sobrecarga
    cout << "\n3. LAMBDA Y SOBRECARGA:" << endl;
    
    gestor.forEachTarea([](TareaBase& tarea) {
        tarea.marcarCompletada();
    });
    
    TareaSimple t1("Tarea A", 1);
    TareaSimple t2("Tarea B", 2);
    TareaSimple t3 = t1 + t2;
    
    cout << "Tarea combinada: ";
    t3.mostrarInfo();
    
    // resultados finales
    cout << "\n4. ESTADO FINAL:" << endl;
    gestor.mostrarTareas();
    
    cout << "\n=== FIN DEL GESTOR ===" << endl;
    
    return 0;
}