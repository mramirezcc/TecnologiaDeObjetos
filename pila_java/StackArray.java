public class StackArray<E> implements Stack<E> {
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

    public E pop() throws ExceptionIsEmpty{
        if(this.isEmpty()){
            throw new ExceptionIsEmpty("No se puede hacer pop");
        }
        E aux = this.data[top];
        this.data[top] = null;
        top--;
        return aux;
    }

    public E top() throws ExceptionIsEmpty{
        if(this.isEmpty()){
            throw new ExceptionIsEmpty("La pila no tiene elementos");
        }
        return this.data[top];
    }

    public boolean isEmpty(){
        return this.data[0] == null;
    }

    public boolean isFull(){
        return this.top == this.data.length - 1;
    }

    public String toString(){
        String str = "Elementos: ";
        for(E elem : this.data){
            if(elem != null)
                str += elem.toString() + ", ";
        }
        return str;
    }
}