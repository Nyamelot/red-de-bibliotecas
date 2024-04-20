


#ifndef USUARIO_H
#define USUARIO_H

#include "persona.h"
#include "inventario.h"

class Usuario : public Persona {
public:
    Usuario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

    void iniciarSesion() override;
    void registrarse() override;
    bool ConsultarDisponibilidad(string, Inventario&) const;
    Libro PedirPrestamo(Inventario&) override;
    void DevolverPrestamo(Libro*, Inventario&);

    
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

/*
bool Usuario::ConsultarDisponibilidad(string nombre_libro, Inventario& inventario) {

}
*/


Libro Usuario::PedirPrestamo(Inventario& inventario) {
    cout << "=== Pedir préstamo === " << endl;
    cout << "Introduzca el libro que desea" << endl;

    string nombreLibro, nombreAutor;
    cin >> nombreLibro;
    
    cout << "Introduzca el autor del libro que desea" << endl;
    cin >> nombreAutor;

    if (ConsultarDisponibilidad(nombreLibro,inventario)) {
        cout << "Libro disponible" << endl;
        Libro libro(nombreLibro, nombreAutor);
        return libro;
    } else {
        cout << "El libro no se encuentra disponible" << endl;
        exit(EXIT_FAILURE);
    }
}

//Devolver prestamo 
void Usuario::DevolverPrestamo(Libro* libro, Inventario& inventario) {
    cout << "=== Devolver préstamo ===" << endl;
    cout << "Introduzca el libro que desea devolver" << endl;

    string nombreLibro, nombreAutor;
    cin >> nombreLibro;
    
    cout << "Introduzca el autor del libro que desea devolver" << endl;
    cin >> nombreAutor;

    inventario.AgregarLibro(libro);

    std::cout << "Libro devuelto con éxito" << std::endl;

}

#endif