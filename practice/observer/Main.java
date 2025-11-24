import java.util.ArrayList;
import java.util.List;

//observer
interface Participant{
    void receive(String groupName, String mensaje);
}

class Group{
    private String name;
    private List<Participant> members = new ArrayList<>();

    public Group(String name){
        this.name = name;
    }

    public void addMember(Participant p){ members.add(p); }
    public void removeMember(Participant p){members.remove(p); }
    //envio usuario a varios usuarios
    public void sendMessage(String sender, String mensaje){
        System.out.println("[" + name + "] " + sender + " dice: " + mensaje);
        for(Participant p : members){
            p.receive(name, sender + ": " + mensaje);
        }
    }

    //envio de sistema
    public void sendSystemMessage(String mensaje){
        System.out.println("\n[" + name + "] (sistema): " + mensaje);
        for(Participant p : members){
            p.receive(name, "(sistema): " + mensaje);
        }
    }
}

//usuario
class Member implements Participant{
    private String nombre;

    public Member(String nombre){
        this.nombre = nombre;
    }

    public void receive(String groupName, String mensaje){
        System.out.println(">@" + nombre + "<-- " + mensaje);
    }

    public String getName(){
        return nombre;
    }
}

public class Main{
    public static void main(String[] args){
        Group familia = new Group("Group whatsApp");

        
        Member c1 = new Member("user001");
        Member a2 = new Member("user002");
        Member m3 = new Member("user003");
        
        familia.addMember(c1);
        familia.addMember(a2);
        familia.addMember(m3);

        familia.sendMessage(c1.getName(), "Hola a todos");
        familia.sendMessage(a2.getName(), "Hola tambien");
        familia.sendMessage(m3.getName(), "buenos dias");

        familia.removeMember(a2);
        familia.sendSystemMessage("user002 salió del grupo");

        familia.sendMessage(c1.getName(), "soy usuario 001 tomando nota");
    }
}
