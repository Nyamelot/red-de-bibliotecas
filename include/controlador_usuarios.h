/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase ControladorUsuarios
*/

#include <iostream>
#include <fstream>

#include "persona.h"
#include "usuario.h"
#include "bibliotecario.h"
#include "administrador.h"

#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

class ControladorUsuarios {
  public:
  ControladorUsuarios() {  }
  ~ControladorUsuarios() {  }
  Persona* IniciarSesion(std::string nombre_usuario, std::string contrasena);
  Persona* Registrarse();
  private:
  // Métodos privados de apoyo
  Persona* BuscaUsuario(std::string nombre_usuario, std::string contrasena);
  Persona* BuscaBibliotecario(std::string nombre_usuario, std::string contrasena);
  Persona* BuscaAdmin(std::string nombre_usuario, std::string contrasena);
  Persona* RegistrarUsuario();
  Persona* RegistrarBibliotecario();
  Persona* RegistrarAdmin();
};

#endif