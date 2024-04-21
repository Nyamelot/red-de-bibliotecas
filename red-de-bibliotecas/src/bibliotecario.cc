/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de métodos de la clase Bibliotecario
*/

#include "bibliotecario.h"

void Bibliotecario::iniciarSesion() {
    cout << "=== Inicio de sesión como bibliotecario ===" << endl;
    Persona::iniciarSesion();
}

void Bibliotecario::registrarse() {
    cout << "=== Registro de bibliotecario ===" << endl;
    Persona::registrarse();
}