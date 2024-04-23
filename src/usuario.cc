
#include <iostream>

#include "usuario.h"

void Usuario::iniciarSesion() {
  std::cout << "=== Inicio de sesión como usuario ===" << endl;
  Persona::iniciarSesion();
}

void Usuario::registrarse() {
  std::cout << "=== Registro de usuario ===" << endl;
  Persona::registrarse();
}

Libro Usuario::PedirPrestamo(Inventario& inventario) {
  std::cout << "=== Pedir préstamo === " << endl;
  std::cout << "Introduzca el libro que desea" << endl;

  std::string nombreLibro, nombreAutor;
  std::cin >> nombreLibro;
    
  std::cout << "Introduzca el autor del libro que desea" << endl;
  std::cin >> nombreAutor;

  if (ConsultarDisponibilidad(nombreLibro,inventario)) {
    std::cout << "Libro disponible" << endl;
    Libro libro(nombreLibro, nombreAutor);
    return libro;
  } else {
    std::cout << "El libro no se encuentra disponible" << endl;
    exit(EXIT_FAILURE);
  }
}

//Devolver prestamo 
void Usuario::DevolverPrestamo(Libro* libro, Inventario& inventario) {
  std::cout << "=== Devolver préstamo ===" << endl;
  std::cout << "Introduzca el libro que desea devolver" << endl;

  std::string nombreLibro, nombreAutor;
  std::cin >> nombreLibro;
    
  std::cout << "Introduzca el autor del libro que desea devolver" << endl;
  std::cin >> nombreAutor;

  inventario.AgregarLibro(libro);

    std::cout << "Libro devuelto con éxito" << std::endl;

}

void Usuario::MainMenu() {
  int option;
  do {
    std::cout << "\n=== MENÚ PRINCIPAL DE USUARIO ===\n";
    std::cout << "  [1] Pedir préstamo\n";
    std::cout << "  [2] Devolver Préstamos\n";
    std::cout << "  [3] Cerrar sesión\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;
    if (option == 1) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
      // std::ifstream inventario("lista_inventario.txt");
      // Inventario inventario_obj(inventario);            
      // this->PedirPrestamo(inventario_obj);
    } else if (option == 2) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
        // std::ifstream inventario("lista_inventario.txt");
        // Inventario inventario_obj(inventario);
    } else if (option == 3) {
      std::cout << "\nCerrarndo sesión...\n";
    } else {
      std::cout << "\nOpción inválida. Intente nuevamente.\n";
    }
    } while (option != 3);
    std::cout << std::endl;
}
