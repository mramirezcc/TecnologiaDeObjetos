public class ExceptionIsEmpty extends Exception{
    public ExceptionIsEmpty(){
        super("El elemento está vacío");
    }

    public ExceptionIsEmpty(String msg){
        super(msg);
    }
}