
public class main {
    public static void main(String[] args) {
        try {
            System.out.println("Creando una pila con capacidad 3...");
            StackArray<Integer> stack = new StackArray<>(3);

            System.out.println("\nEstado inicial:");
            System.out.println("¿Está vacía? " + stack.isEmpty());
            System.out.println(stack);

            System.out.println("\nInsertando 10, 20, 30...");
            stack.push(10);
            stack.push(20);
            stack.push(30);

            System.out.println("\n¿Está llena? " + stack.isFull());
            System.out.println(stack);

            System.out.println("\nIntentando insertar 40 (debería fallar):");
            stack.push(40);

            System.out.println("\nTop de la pila:");
            System.out.println(stack.top());

            System.out.println("\nHaciendo pop:");
            System.out.println("Elemento sacado: " + stack.pop());
            System.out.println(stack);

            System.out.println("\nHaciendo pop nuevamente:");
            System.out.println("Elemento sacado: " + stack.pop());
            System.out.println(stack);

            System.out.println("\nHaciendo pop una vez más:");
            System.out.println("Elemento sacado: " + stack.pop());
            System.out.println(stack);

            System.out.println("\nIntentando hacer pop en pila vacía (debería lanzar excepción):");
            System.out.println("Elemento sacado: " + stack.pop());

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
}