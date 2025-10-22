package pila_java;

public class ExceptionsIsEmpty extends Exception{
    public ExceptionsIsEmpty(){
        super("pila vacía");
    }
    public ExceptionsIsEmpty(String msg){
        super(msg);
    }
}
