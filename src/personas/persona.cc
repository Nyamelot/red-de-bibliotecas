/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definicón de métodos de la clase Persona
*/

#include<iostream>

#include "personas/persona.h"

void Persona::iniciarSesion() {
  std::cout << "=== Inicio de sesión ===" << std::endl;
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> nombreUsuario_;
  std::cout << "Introduzca la contraseña: ";
  std::cin >> contrasena_;
}

void Persona::registrarse() {
  std::cout << "=== Registro de usuario ===" << std::endl;
  std::cout << "Introduzca su nombre: ";
  std::cin >> nombre_;
  std::cout << "Introduzca sus apellidos: ";
  std::cin >> apellidos_;
  std::cout << "Introzca nombre de usuario: ";
  std::cin >> nombreUsuario_;
  std::cout << "Introduzca su DNI: ";
  std::cin >> dni_;
  std::cout << "Introduzca su correo electrónico: ";
  std::cin >> correoElectronico_;
  std::cout << "Establesca una contraseña: ";
  std::cin >> contrasena_;
  std::cout << "Introduce tu rol (Administrador, Usuario, Bibliotecario): ";
  std::cin >> rol_;
}
