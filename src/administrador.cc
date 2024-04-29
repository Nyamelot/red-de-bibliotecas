/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de los métodos de la clase Inventario
*/
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

void Administrador::MainMenu(Inventario* inventario, RedBibliotecas* red) {
  std::cout << "\n=== MENÚ PRINCIPAL DE ADMINISTRADOR ===\n";
  int option;
  do {
    std::cout << "  [0] Cerrar sesión\n";
    std::cout << "  [1] Mostrar Inventario\n";
    std::cout << "  [2] Mostrar Bibliotecas\n";
    std::cout << "  [3] Buscar un libro\n";
    std::cout << "  [4] Añadir un libro\n";
    std::cout << "  [5] Eliminar un libro\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;

    if (option == 0) {
      std::cout << "\nCerrando sesión...\n\n";
    } else if (option == 1) {
      std::cout << "\n=== INVENTARIO ===\n";
      inventario->MostrarInventario();
      std::cout << std::endl;
    } else if (option == 2) {
      std::cout << "\n=== BUSCAR LIBRO ===\n";
      red->MostrarRed();
    } else if (option == 3) {
      std::cout << "\n=== BIBLIOTECAS ===\n";
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
      std::cout << "\n=== AÑADIR LIBRO ===\n";
      std::string nombre_libro, nombre_autor;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      std::cout << "Introduzca el nombre del autor: ";
      std::getline(std::cin >> std::ws, nombre_autor);
      Libro* libro = new Libro(nombre_libro, nombre_autor);
      inventario->AgregarLibro(libro);
      std::cout << std::endl;
    } else if (option == 5) {
      std::cout << "\n=== ELIMINAR LIBRO ===\n";
      std::string nombre_libro;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      if (inventario->BuscarLibro(nombre_libro) != nullptr) {
        inventario->EliminarLibro(nombre_libro);
        std::cout << "\033[32m" << "\nEl libro se ha eliminado correctamente.\n\n" << "\033[0m";
      } else {
        std::cout << "\033[31m" << "\nEl libro NO se encuentra en el inventario.\n\n" << "\033[0m";
      }
    } else {
      std::cout << "\nOpción inválida. Intente nuevamente.\n";
    }
  } while (option != 0);
  std::cout << std::endl;
}
