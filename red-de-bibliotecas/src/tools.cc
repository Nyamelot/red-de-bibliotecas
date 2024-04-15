/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de diferentes funciones de utilidad para el programa
*/

#include <iostream>
#include <fstream>
#include <optional>

#include "usuarios.h"

std::optional<Persona*> IniciarSesion(std::string nombre_usuario, std::string contraseña) {
  // no sé si esta línea seguirá funcionando si el fichero no se encuentra en el mismo directorio que el ejecutable
  std::ifstream fichero_usuarios{"usuarios_registrados.txt"};
  std::string nombre_a_comprobar;
  std::string contraseña_a_comprobar;
  int numero_intentos{0};
  Persona* persona_a_retornar = nullptr;
  while (fichero_usuarios >> nombre_a_comprobar >> contraseña) {
    if (nombre_usuario == nombre_a_comprobar) {
      while (contraseña != contraseña_a_comprobar && numero_intentos < 4) {
        std::cout << "error. La contraseña no es correta." << std::endl;
        std::cin >> contraseña;
        ++numero_intentos;
      }
      if (numero_intentos == 4) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        return std::nullopt;
      }
      persona_a_retornar = new Usuario();
      return persona_a_retornar;
    }
  }
  fichero_usuarios.close();
  std::ifstream fichero_bibliotecarios{"bibliotecarios_registrados.txt"};
  while (fichero_bibliotecarios >> nombre_a_comprobar >> contraseña) {
    if (nombre_usuario == nombre_a_comprobar) {
      while (contraseña != contraseña_a_comprobar && numero_intentos < 4) {
        std::cout << "error. La contraseña no es correta." << std::endl;
        std::cin >> contraseña;
        ++numero_intentos;
      }
      if (numero_intentos == 4) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        return std::nullopt;
      }
      persona_a_retornar = new Bibliotecario();
      return persona_a_retornar;
    }
  }
  std::cout << "error. No se ha encontrado el usuario." << std::endl;
  fichero_bibliotecarios.close();
  return std::nullopt;
}