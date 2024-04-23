
#include <iostream>

#include "bibliotecario.h"

void Bibliotecario::iniciarSesion() {
  std::cout << "=== Inicio de sesión como bibliotecario ===" << endl;
  Persona::iniciarSesion();
}

void Bibliotecario::registrarse() {
  std::cout << "=== Registro de bibliotecario ===" << endl;
  Persona::registrarse();
}

void Bibliotecario::MainMenu() {
  std::cout << "\n=== MENÚ PRINCIPAL DE BIBLIOTECARIO ===\n";
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
        std::cout << "\nCerrarndo sesión...\n";
        break;
            
      default:
        std::cout << "\nOpción inválida. Intente nuevamente.\n";
        break;
    }
  } while (option != 4);
  std::cout << std::endl;
}
