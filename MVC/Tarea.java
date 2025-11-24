package MVC;

public class Tarea {
    private String descripcion;
    private boolean completada;
    private int id;
    private static int contadorId = 1;

    public Tarea(String descripcion) {
        this.id = contadorId++;
        this.descripcion = descripcion;
        this.completada = false;
    }
    
    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public boolean isCompletada() {
        return completada;
    }

    public void setCompletada(boolean completada) {
        this.completada = completada;
    }

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        String estado = completada ? "[✓]" : "[ ]";
        return id + ". " + estado + " " + descripcion;
    }
}