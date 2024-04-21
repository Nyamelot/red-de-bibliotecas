/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definicón de métodos de la clase Persona
*/

#include "persona.h"

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