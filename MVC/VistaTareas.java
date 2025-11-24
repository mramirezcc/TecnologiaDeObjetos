package MVC;
import java.util.List;
import java.util.Scanner;

public class VistaTareas {
    private Scanner scanner;

    public VistaTareas() {
        this.scanner = new Scanner(System.in);
    }

    public void mostrarMenu() {
        System.out.println("\n=== GESTOR DE TAREAS ===");
        System.out.println("1. Agregar tarea");
        System.out.println("2. Marcar tarea como completada");
        System.out.println("3. Mostrar todas las tareas");
        System.out.println("4. Mostrar tareas pendientes");
        System.out.println("5. Mostrar tareas completadas");
        System.out.println("6. Salir");
        System.out.print("Seleccione una opción: ");
    }

    public String obtenerDescripcionTarea() {
        System.out.print("Ingrese la descripción de la tarea: ");
        return scanner.nextLine();
    }

    public int obtenerIdTarea() {
        System.out.print("Ingrese el ID de la tarea: ");
        while (!scanner.hasNextInt()) {
            System.out.println("Por favor, ingrese un número válido.");
            scanner.next();
            System.out.print("Ingrese el ID de la tarea: ");
        }
        int id = scanner.nextInt();
        scanner.nextLine(); // Limpiar el buffer
        return id;
    }

    public void mostrarTareas(List<Tarea> tareas) {
        if (tareas.isEmpty()) {
            System.out.println("No hay tareas para mostrar.");
            return;
        }

        System.out.println("\n=== LISTA DE TAREAS ===");
        for (Tarea tarea : tareas) {
            System.out.println(tarea);
        }
    }

    public void mostrarMensaje(String mensaje) {
        System.out.println(mensaje);
    }

    public void mostrarError(String error) {
        System.out.println("Error: " + error);
    }

    public void cerrarScanner() {
        scanner.close();
    }
}