
#include "persona.h"

class Usuario : public Persona {
public:
    Usuario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

    void iniciarSesion() override;
    void registrarse() override;

    void buscarLibro() {
        cout << "Buscando libro en el catálogo...\n";
    }

    void hacerReserva() {
        cout << "Haciendo reserva de un libro...\n";
    }

    void devolverLibro() {
        cout << "Devolviendo un libro...\n";
    }

    void solicitarSalaEstudio() {
        cout << "Solicitando sala de estudio...\n";
    }

};

void Usuario::iniciarSesion() {
    cout << "=== Inicio de sesión como usuario ===" << endl;
    Persona::iniciarSesion();
}

void Usuario::registrarse() {
    cout << "=== Registro de usuario ===" << endl;
    Persona::registrarse();
}

