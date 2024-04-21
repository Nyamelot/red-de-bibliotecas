/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Programa para dar soporte a una red de bibliotecas
*/

#include "controlador_usuarios.h"

int main(int argc, char* argv[]) {
  // Incorporar menú con opciones
  std::string usuario{""};
  std::string contraseña{""};
  std::cin >> usuario >> contraseña;
  ControladorUsuarios controlador;
  Persona* prueba = controlador.IniciarSesion(usuario, contraseña);
  if (prueba != nullptr) {
    std::cout << "correcto" << std::endl;
  }
  Persona* prueba2 = controlador.Registrarse();
}