
#include <iostream>
#include <string>

using namespace std;

// Clase base Persona
class Persona {
 protected:
    string nombre;
    string apellidos;
    string dni;
    string correoElectronico;

 public:
    Persona(string _nombre, string _apellidos, string _dni, string _correoElectronico)
        : nombre(_nombre), apellidos(_apellidos), dni(_dni), correoElectronico(_correoElectronico) {}

    virtual void recogerinformacion() {
        cout << "Introduce el nombre: ";
        cin >> nombre;
        cout << "Introduce los apellidos: ";
        cin >> apellidos;
        cout << "Introduce el DNI: ";
        cin >> dni;
        cout << "Introduce el correo electrónico: ";
        cin >> correoElectronico;
    }

    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellidos: " << apellidos << endl;
        cout << "DNI: " << dni << endl;
        cout << "Correo Electrónico: " << correoElectronico << endl;
    }
};


