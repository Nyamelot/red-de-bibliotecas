/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la dedinicón de métodos de la clase Administrador
*/

#include "administrador.h"

void Administrador::iniciarSesion() {
    cout << "=== Inicio de sesión como administrador ===" << endl;
    Persona::iniciarSesion();
}

void Administrador::registrarse() {
    cout << "=== Registro de administrador ===" << endl;
    Persona::registrarse();
}