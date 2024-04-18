/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Programa para dar soporte a una red de bibliotecas
*/

#include <iostream>

#include "controlador_usuarios.h"

int main(int argc, char* argv[]) {
  // Incorporar menú con opciones
  std::string antonio{"antonio"};
  ControladorUsuarios controlador;
  Persona* prueba = controlador.IniciarSesion(antonio, "juan");
  if (prueba != nullptr) {
    std::cout << "correcto" << std::endl;
  }
}