#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Observer {
public:
    virtual void update(const string& mensaje) = 0;
};

class NotificationSystem {
    private:
        vector<Observer*> observers;  //lista usuarios
    public:
        void addObserver(Observer* obs) {
            observers.push_back(obs);
        }

        void removeObserver(Observer* obs) {
            observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
        }

        void notifyAll(const string& mensaje) {
            for (Observer* obs : observers) {
                obs->update(mensaje);  // Notifica a cada usuario
            }
        }

        void nuevaNotificacion(const string& mensaje) {
            cout << "\n📢 Nueva notificación del sistema: " << mensaje << endl;
            notifyAll(mensaje);
        }
};

// -------------------------------
// Observador concreto (Usuario)
// -------------------------------
class Usuario : public Observer {
private:
    string nombre;
public:
    Usuario(const string& n) : nombre(n) {}
    void update(const string& mensaje) override {
        cout << "👤 " << nombre << " recibió: " << mensaje << endl;
    }
};

// -------------------------------
// Programa principal
// -------------------------------
int main() {
    // Creamos el sistema (Sujeto)
    NotificationSystem sistema;

    // Creamos usuarios (Observadores)
    Usuario u1("Carlos");
    Usuario u2("Ana");
    Usuario u3("María");

    // Registramos a los usuarios
    sistema.addObserver(&u1);
    sistema.addObserver(&u2);
    sistema.addObserver(&u3);

    // Enviamos notificaciones
    sistema.nuevaNotificacion("¡Nuevo mensaje en el grupo!");
    sistema.nuevaNotificacion("Actualización disponible del sistema.");
    sistema.nuevaNotificacion("Evento programado para mañana.");

    // Eliminamos un usuario
    sistema.removeObserver(&u2);
    cout << "\n🚫 Ana se ha desuscrito de las notificaciones.\n";

    // Nueva notificación solo para los restantes
    sistema.nuevaNotificacion("Promoción exclusiva para usuarios activos.");

    return 0;
}
