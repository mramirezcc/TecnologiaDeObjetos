package MVC;

public class Main {
    public static void main(String[] args) {
        GestorTareas gestorTareas = new GestorTareas();
        VistaTareas vistaTareas = new VistaTareas();
        ControladorTareas controlador = new ControladorTareas(gestorTareas, vistaTareas);

        boolean ejecutando = true;

        System.out.println("Bienvenido al Gestor de Tareas MVC");

        while (ejecutando) {
            try {
                vistaTareas.mostrarMenu();
                int opcion = Integer.parseInt(vistaTareas.obtenerDescripcionTarea());

                switch (opcion) {
                    case 1:
                        controlador.agregarTarea();
                        break;
                    case 2:
                        controlador.marcarTareaCompletada();
                        break;
                    case 3:
                        controlador.mostrarTodasLasTareas();
                        break;
                    case 4:
                        controlador.mostrarTareasPendientes();
                        break;
                    case 5:
                        controlador.mostrarTareasCompletadas();
                        break;
                    case 6:
                        ejecutando = false;
                        vistaTareas.mostrarMensaje("¡Hasta luego!");
                        break;
                    default:
                        vistaTareas.mostrarError("Opción no válida. Por favor, seleccione 1-6.");
                }
            } catch (NumberFormatException e) {
                vistaTareas.mostrarError("Por favor, ingrese un número válido.");
            } catch (Exception e) {
                vistaTareas.mostrarError("Error inesperado: " + e.getMessage());
            }
        }

        vistaTareas.cerrarScanner();
    }
}