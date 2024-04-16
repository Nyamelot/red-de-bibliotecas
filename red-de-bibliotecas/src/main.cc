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

#include "tools.h"
#include "usuarios.h"

int main(int argc, char* argv[]) {
  // Incorporar menú con opciones
  std::optional<Persona*> prueba = IniciarSesion("antonio", "antonio");
  if (prueba.has_value()) {
    std::cout << "correcto" << std::endl;
  }
}