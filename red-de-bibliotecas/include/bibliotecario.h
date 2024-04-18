
#include "persona.h"

#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

class Bibliotecario : public Persona {
public:
    Bibliotecario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

    void iniciarSesion() override;
    void registrarse() override;
    void ComprobarCatalogo();
    bool ConsultarDisponibilidad(string) const;

     void ayudarUsuario() {
        cout << "Asistiendo a un usuario...\n";
    }

    void anadirLibroCatalogo() {
        cout << "Añadiendo libro al catálogo...\n";
    }

    void eliminarLibroCatalogo() {
        cout << "Eliminando libro del catálogo...\n";
    }

    void gestionarPrestamos() {
        cout << "Gestionando préstamos...\n";
    }

    void gestionarMultas() {
        cout << "Gestionando multas...\n";
    }

};

void Bibliotecario::iniciarSesion() {
    cout << "=== Inicio de sesión como bibliotecario ===" << endl;
    Persona::iniciarSesion();
}

void Bibliotecario::registrarse() {
    cout << "=== Registro de bibliotecario ===" << endl;
    Persona::registrarse();
}

#endif