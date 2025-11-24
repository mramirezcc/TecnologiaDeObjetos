public class StackArray<E> {
    private E[] data;
    private int top;

    @SuppressWarnings("unchecked")
    public StackArray(int n){
        n = n < 1 ? 1 : n;
        this.data = (E[]) new Object[n];
        this.top = -1;
    }

    public void push(E x){
        if(this.isFull()){
            System.out.println("No se puede insertar " + x.toString() + ": Pila llena");
            return;
        }else{
            this.top++;
            this.data[top] = x;
            System.out.println("Nuevo top: " + this.top);
        }
    }

    public E pop() throws Exception {
        if(this.isEmpty()){
            throw new Exception("No se puede hacer pop: Pila vacía");
        }
        E aux = this.data[top];
        this.data[top] = null;
        top--;
        return aux;
    }

    public E top() throws Exception {
        if(this.isEmpty()){
            throw new Exception("La pila no tiene elems");
        }
        return this.data[top];
    }

    public boolean isEmpty(){
        return this.top == -1;
    }

    public boolean isFull(){
        return this.top == this.data.length - 1;
    }

    public String toString(){
        StringBuilder str = new StringBuilder("elems: ");
        for(E elem : this.data){
            if(elem != null)
                str.append(elem.toString()).append(", ");
        }
        return str.toString();
    }

    // Método main para pruebas rápidas (opcional)
    public static void main(String[] args) {
        try {
            StackArray<Integer> stack = new StackArray<>(3);
            stack.push(10);
            stack.push(20);
            System.out.println(stack);
            System.out.println("Top: " + stack.top());
            System.out.println("Pop: " + stack.pop());
            System.out.println(stack);
            stack.pop();
            stack.pop(); // Esto lanzará excepción
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}