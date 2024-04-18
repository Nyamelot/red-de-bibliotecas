

#include <iostream>
#include <string>

#include "libro.h"

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

// Clase base Persona
class Persona {
protected:
    string nombre_;
    string apellidos_;
    string dni_;
    string correoElectronico_;
    string rol_;
    string contrasena_;
    string nombreUsuario_;


public:
    Persona(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : nombre_(nombre), apellidos_(apellidos), dni_(dni), correoElectronico_(correoElectronico),  contrasena_(contrasena), nombreUsuario_(nombreUsuario){}

    virtual void iniciarSesion();
    virtual void registrarse();
    virtual bool ConsultarDisponibilidad(string) const;
    virtual Libro PedirPrestamo();
};

void Persona::iniciarSesion() {
    cout << "=== Inicio de sesión ===" << endl;
    cout << "Introduzca el nombre de usuario: ";
    cin >> nombreUsuario_;
    cout << "Introduzca la contraseña: ";
    cin >> contrasena_;
}

void Persona::registrarse() {
    cout << "=== Registro de usuario ===" << endl;
    cout << "Introduzca su nombre: ";
    cin >> nombre_;
    cout << "Introduzca sus apellidos: ";
    cin >> apellidos_;
    cout << "Introzca nombre de usuario: ";
    cin >> nombreUsuario_;
    cout << "Introduzca su DNI: ";
    cin >> dni_;
    cout << "Introduzca su correo electrónico: ";
    cin >> correoElectronico_;
    cout << "Establesca una contraseña: ";
    cin >> contrasena_;
    cout << "Introduce tu rol (Administrador, Usuario, Bibliotecario): ";
    cin >> rol_;
}


#endif