
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

void Administrador::MainMenu(Inventario* inventario) {
  std::cout << "\n=== MENÚ PRINCIPAL DE ADMINISTRADOR ===\n";
  int option;
  do {
    std::cout << "  [0] Cerrar sesión\n";
    std::cout << "  [1] Mostrar Inventario\n";
    std::cout << "  [2] Mostrar Bibliotecas\n";
    std::cout << "  [3] Opción 3\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
      case 0:
        std::cout << "\nCerrarndo sesión...\n";
        break;

      case 1:
        std::cout << "\n=== INVENTARIO ===\n";
        inventario->MostrarInventario();
        std::cout << std::endl;
        break;

      case 2:
        std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
        break;

      case 3:
        std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
        break;
            
      default:
        std::cout << "\nOpción inválida. Intente nuevamente.\n";
        break;
    }
  } while (option != 0);
  std::cout << std::endl;
}
