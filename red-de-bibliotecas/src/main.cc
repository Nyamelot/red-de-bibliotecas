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

void LoginMenu() {
  std::cout << "\033[32m" << "BIENVENIDO A LA SEDE ELECTRONICA DE LA RED DE BIBLIOTECAS!\n\n" << "\033[0m";

  int option;
  do {
  std::cout << "=== MENÚ INICIAL ===\n";
  std::cout << "  [1] Iniciar sesión\n";
  std::cout << "  [2] Registrarse\n";
  std::cout << "  [3] Salir\n";
  std::cout << "  Introduzca una opción: ";
  std::cin >> option;
  if (option < 1 || option > 3) {
    std::cout << "\nerror. Opción no válida. Intentelo de nuevo\n\n";
  }
  if (option == 1) {
    std::cout << "\n=== INICIAR SESIÓN ===\n";
    std::string usuario{""};
    std::string contrasena{""};
    std::cout << "Introduzca su nombre de usuario: ";
    std::cin >> usuario;
    std::cout << "Introduzca su contraseña: ";
    std::cin >> contrasena;
    ControladorUsuarios controlador;
    Persona* persona = controlador.IniciarSesion(usuario, contrasena);
    persona->MainMenu();
  } else if (option == 2) {
    std::cout << "\n=== RESGISTRARSE ===\n";
    ControladorUsuarios controlador;
    Persona* nuevo_usuario = controlador.Registrarse();
    nuevo_usuario->MainMenu();
  }
  } while (option != 3);
  std::cout << "\nSaliendo de la sede...\n";
}

int main() {
  LoginMenu();
  return 0;
}