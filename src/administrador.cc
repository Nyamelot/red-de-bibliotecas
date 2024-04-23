
#include <iostream>

#include "administrador.h"

void Administrador::iniciarSesion() { 
  std::cout << "=== Inicio de sesión como administrador ===" << endl;
  Persona::iniciarSesion();
}

void Administrador::registrarse() {
  std::cout << "=== Registro de administrador ===" << endl;
  Persona::registrarse();
}

void Administrador::MainMenu() {
  std::cout << "\n=== MENÚ PRINCIPAL DE ADMINISTRADOR ===\n";
  int option;
  do {
    std::cout << "  [1] Opción 1\n";
    std::cout << "  [2] Opción 2\n";
    std::cout << "  [3] Opción 3\n";
    std::cout << "  [4] Cerrar sesión\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
      case 1:
      std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
      break;

      case 2:
        std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
        break;

      case 3:
        std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
        break;

      case 4:
        std::cout << "\nCerrando sesión...\n";
        break;

      default:
        std::cout << "\nOpción inválida. Intente nuevamente.\n";
        break;
    }
  } while (option != 4);
  std::cout << std::endl;
}
