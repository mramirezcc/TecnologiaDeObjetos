package pila_java;
public class StackArray<E> implements Stack<E> {
    private E[] data;
    private int top; //indice

    public StackArray(int n){
        if(n < 1){ n = 1; }
        this.data = (E[]) new Object[n];
        this.top = -1;
    }

    public void push(E x){
        this.top++;
        this.data[top] = x;
    }
    public E pop() throws ExceptionsIsEmpty{

        this.data[top] = null;
        this.top--;
        return null;
    }
    public E top() throws ExceptionsIsEmpty{

        System.out.println(this.data[top]);
        return null;
    }
    public boolean isEmpty(){
        return this.data[0] == null;
    }

    public int size(){
        return this.data.length;
    }

    public String toString(){
        String str = "Pila: ";
        for(E elem : this.data){
            if(elem != null)
                str += elem.toString() + ", ";
        }
        return str;
    }
}
