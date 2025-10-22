package pila_java;

public interface Stack<E> {
    void push(E x);
    E pop() throws ExceptionsIsEmpty;
    E top() throws ExceptionsIsEmpty;
    boolean isEmpty();
    String toString();
}
