#include <iostream>
#include "GestorTareas.h"
#include "Tarea.h"

using namespace std;

int main() {
    GestorTareas gestor;
    
    // Crear tareas
    Tarea t1("Estudiar C++", 2);
    Tarea t2("Hacer ejercicio", 1);
    Tarea t3("Comprar comida", 3);
    
    gestor.agregarTarea(t1);
    gestor.agregarTarea(t2);
    gestor.agregarTarea(t3);
    
    gestor.mostrarTareas();
    
    // Filtrar tareas de alta prioridad
    auto filtroAltaPrioridad = [](const Tarea& t) { 
        return t.getPrioridad() >= 2; 
    };
    
    cout << "\n=== TAREAS DE ALTA PRIORIDAD ===" << endl;
    auto tareasAltas = gestor.filtrarTareas(filtroAltaPrioridad);
    for (const auto& tarea : tareasAltas) {
        cout << "- " << tarea.getDescripcion() << " [Pri: " << tarea.getPrioridad() << "]" << endl;
    }
    
    // Modificar todas las tareas
    auto agregarPrefijo = [](Tarea& t) {
        t.modificarDescripcion([](const string& desc) {
            return "- " + desc;
        });
    };
    
    cout << "\n=== MODIFICACION DE TAREAS ===" << endl;
    gestor.forEachTarea(agregarPrefijo);
    gestor.mostrarTareas();
    
    // Filtrar tareas pendientes
    cout << "\n=== TAREAS PENDIENTES ===" << endl;
    auto tareasPendientes = gestor.filtrarTareas(
        [](const Tarea& t) { return !t.estaCompletada(); }
    );
    
    for (const auto& tarea : tareasPendientes) {
        cout << "- " << tarea.getDescripcion() << endl;
    }
    
    // SObrecarga de operador +
    cout << "\n=== COMBINACION TAREAS ===" << endl;
    Tarea t5("Limpiar casa", 2);
    Tarea t6("Lavar ropa", 1);
    Tarea combinada = t5 + t6;
    cout << "Tarea combinada: " << combinada.getDescripcion() << endl;
    
    // Probar función friend
    cout << "\n=== INTERCAMBIANDO TAREAS ===" << endl;
    Tarea ta("Comer", 1);
    Tarea tb("Dormir", 3);
    cout << "Antes: " << ta.getDescripcion() << " y " << tb.getDescripcion() << endl;
    intercambiarTareas(ta, tb);
    cout << "Despues: " << ta.getDescripcion() << " y " << tb.getDescripcion() << endl;
    
    return 0;
}