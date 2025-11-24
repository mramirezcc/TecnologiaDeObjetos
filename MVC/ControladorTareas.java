package MVC;

import java.util.List;

public class ControladorTareas {
    private GestorTareas gestorTareas;
    private VistaTareas vistaTareas;

    public ControladorTareas(GestorTareas gestorTareas, VistaTareas vistaTareas) {
        this.gestorTareas = gestorTareas;
        this.vistaTareas = vistaTareas;
    }

    public void agregarTarea() {
        String descripcion = vistaTareas.obtenerDescripcionTarea();
        if (descripcion != null && !descripcion.trim().isEmpty()) {
            gestorTareas.agregarTarea(descripcion);
            vistaTareas.mostrarMensaje("Tarea agregada exitosamente.");
        } else {
            vistaTareas.mostrarError("La descripción no puede estar vacía.");
        }
    }

    public void marcarTareaCompletada() {
        int id = vistaTareas.obtenerIdTarea();
        if (gestorTareas.existeTarea(id)) {
            gestorTareas.marcarTareaCompletada(id);
            vistaTareas.mostrarMensaje("Tarea marcada como completada.");
        } else {
            vistaTareas.mostrarError("No existe una tarea con el ID: " + id);
        }
    }

    public void mostrarTodasLasTareas() {
        List<Tarea> tareas = gestorTareas.obtenerTareas();
        vistaTareas.mostrarTareas(tareas);
    }

    public void mostrarTareasPendientes() {
        List<Tarea> tareasPendientes = gestorTareas.obtenerTareasPendientes();
        vistaTareas.mostrarTareas(tareasPendientes);
    }

    public void mostrarTareasCompletadas() {
        List<Tarea> tareasCompletadas = gestorTareas.obtenerTareasCompletadas();
        vistaTareas.mostrarTareas(tareasCompletadas);
    }
}