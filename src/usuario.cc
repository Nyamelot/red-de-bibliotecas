
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

void Usuario::MainMenu(Inventario* inventario, RedBibliotecas* red) {
  int option;
  do {
    std::cout << "\n=== MENÚ PRINCIPAL DE USUARIO ===\n";
    std::cout << "  [0] Cerrar Sesión\n";
    std::cout << "  [1] Mostrar Inventario\n";
    std::cout << "  [2] Mostrar Bibliotecas\n";
    std::cout << "  [3] Buscar un libro\n";
    std::cout << "  [4] Buscar una biblioteca\n";
    std::cout << "  [5] Pedir préstamo\n";
    std::cout << "  [6] Devolver Préstamos\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;
    if (option == 0) {
      std::cout << "\nCerrando sesión...\n\n";
    } else if (option == 1) {
      std::cout << "\n=== INVENTARIO ===\n";
      inventario->MostrarInventario();
      std::cout << std::endl;
    } else if (option == 2) {
        std::cout << "\n=== BIBLIOTECAS ===\n";
        red->MostrarRed();
    } else if (option == 3) {
      std::cout << "\n=== BUSCAR LIBRO ===\n";
      std::string nombre_libro;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      if (inventario->BuscarLibro(nombre_libro) != nullptr) {
        std::cout << "\033[32m" << "\nEl libro se encuentra en el inventario.\n" << "\033[0m";
        inventario->BuscarLibro(nombre_libro)->MostrarInformacion();
        std::cout << endl;
      } else {
        std::cout << "\033[31m" << "\nEl libro NO se encuentra en el inventario.\n\n" << "\033[0m";
      }
    } else if (option == 4) {
      std::cout << "\n=== BUSCAR BIBLIOTECA ===\n";
      std::string nombre_biblioteca;
      std::cout << "Introduzca el nombre de la biblioteca: ";
      std::getline(std::cin >> std::ws, nombre_biblioteca);
      if (red->BuscarBiblioteca(nombre_biblioteca) != nullptr) {
        std::cout << "\033[32m" << "\nLa biblioteca se encuentra en la red.\n" << "\033[0m";
        red->BuscarBiblioteca(nombre_biblioteca)->MostrarInformacionBiblioteca();
        std::cout << endl;
      } else {
        std::cout << "\033[31m" << "\nLa biblioteca NO se encuentra en la red.\n\n" << "\033[0m";
      }
    } else if (option == 5) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
      // std::ifstream inventario("lista_inventario.txt");
      // Inventario inventario_obj(inventario);            
      // this->PedirPrestamo(inventario_obj);
    } else if (option == 6) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
        // std::ifstream inventario("lista_inventario.txt");
        // Inventario inventario_obj(inventario);
    } else {
      std::cout << "\nOpción inválida. Intente nuevamente.\n";
    }
    } while (option != 0);
}
