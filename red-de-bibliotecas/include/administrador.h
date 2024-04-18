
#include "persona.h"

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Persona {
public:
    Administrador(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico,contrasena, nombreUsuario ) {}


    void iniciarSesion() override;
    void registrarse() override;
    bool ConsultarDisponibilidad(string) const;
    
     void gestionarUsuarios() {
        cout << "Gestionando usuarios del sistema...\n";
    }

    void anadirNuevaBiblioteca() {
        cout << "Añadiendo nueva biblioteca a la red...\n";
    }

    void gestionarServiciosOnline() {
        cout << "Gestionando servicios online...\n";
    }

    void gestionarMedidasSeguridad() {
        cout << "Gestionando medidas de seguridad...\n";
    }

    void gestionarUsuariosSistema() {
        cout << "Gestionando usuarios del sistema...\n";
    }

};

void Administrador::iniciarSesion() {
    cout << "=== Inicio de sesión como administrador ===" << endl;
    Persona::iniciarSesion();
}

void Administrador::registrarse() {
    cout << "=== Registro de administrador ===" << endl;
    Persona::registrarse();
}

#endif