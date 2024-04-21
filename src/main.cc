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
  std::cout << "BIENVENIDO A LA SEDE ELECTRONICA DE LA RED DE BIBLIOTECAS!\n\n";

  int option;
  do {
  std::cout << "=======MENÚ INICIAL=======\n";
  std::cout << "  [1] Iniciar sesión\n";
  std::cout << "  [2] Registrarse\n";
  std::cout << "  [3] Salir\n";
  std::cout << "  Introduzca una opción: ";
  std::cin >> option;
  if (option < 1 || option > 3) {
    std::cout << "error. Opción no válida.\n";
    exit(EXIT_FAILURE);
  }
  if (option == 1) {
    std::cout << "\n=======INICIAR SESIÓN=======\n";
    std::string usuario{""};
    std::string contrasena{""};
    std::cout << "Introduzca su nombre de usuario: ";
    std::cin >> usuario;
    std::cout << "Introduzca su contraseña: ";
    std::cin >> contrasena;
    ControladorUsuarios controlador;
    Persona* persona = controlador.IniciarSesion(usuario, contrasena);
  } else if (option == 2) {
    std::cout << "\n=======RESGISTRARSE=======\n";
    ControladorUsuarios controlador;
    Persona* nuevo_usuario = controlador.Registrarse();
  } else if (option == 3) {
    std::cout << "\n=======SALIR DE LA SEDE=======\n";
    std::cout << "Saliendo del programa...\n";
    exit(EXIT_SUCCESS);
  }
  } while (option == 2);
}

int main() {
  LoginMenu();
  return 0;
}