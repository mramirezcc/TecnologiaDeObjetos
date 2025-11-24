package MVC;
import java.util.ArrayList;
import java.util.List;

public class GestorTareas {
    private List<Tarea> tareas;

    public GestorTareas() {
        this.tareas = new ArrayList<>();
    }

    public void agregarTarea(String descripcion) {
        Tarea nuevaTarea = new Tarea(descripcion);
        tareas.add(nuevaTarea);
    }

    public void marcarTareaCompletada(int id) {
        for (Tarea tarea : tareas) {
            if (tarea.getId() == id) {
                tarea.setCompletada(true);
                return;
            }
        }
        System.out.println("No se encontró una tarea con ID: " + id);
    }

    public List<Tarea> obtenerTareas() {
        return new ArrayList<>(tareas);
    }

    public List<Tarea> obtenerTareasPendientes() {
        List<Tarea> pendientes = new ArrayList<>();
        for (Tarea tarea : tareas) {
            if (!tarea.isCompletada()) {
                pendientes.add(tarea);
            }
        }
        return pendientes;
    }

    public List<Tarea> obtenerTareasCompletadas() {
        List<Tarea> completadas = new ArrayList<>();
        for (Tarea tarea : tareas) {
            if (tarea.isCompletada()) {
                completadas.add(tarea);
            }
        }
        return completadas;
    }

    public boolean existeTarea(int id) {
        for (Tarea tarea : tareas) {
            if (tarea.getId() == id) {
                return true;
            }
        }
        return false;
    }
}