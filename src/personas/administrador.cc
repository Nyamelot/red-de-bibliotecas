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

#include "personas/administrador.h"

void Administrador::iniciarSesion() { 
  std::cout << "=== Inicio de sesión como administrador ===" << std::endl;
  Persona::iniciarSesion();
}

void Administrador::registrarse() {
  std::cout << "=== Registro de administrador ===" << std::endl;
  Persona::registrarse();
}

void Administrador::MainMenu(Inventario* inventario, RedBibliotecas* red) {
  int option;
  do {
    std::cout << "\n\033[1;33m=== MENÚ PRINCIPAL DEL ADMINISTRADOR ===\033[0m\n";
    std::cout << "  [0] Cerrar sesión\n";
    std::cout << "  [1] Mostrar Inventario\n";
    std::cout << "  [2] Mostrar Bibliotecas\n";
    std::cout << "  [3] Buscar un libro\n";
    std::cout << "  [4] Añadir un libro\n";
    std::cout << "  [5] Eliminar un libro\n";
    std::cout << "  [6] Buscar una biblioteca\n";
    std::cout << "  [7] Añadir una biblioteca\n";
    std::cout << "  [8] Eliminar una biblioteca\n";
    std::cout << "  [9] Eliminar la cuenta\n";
    std::cout << "  Seleccione una opción: ";
    std::cin >> option;

    if (option == 0) {
      std::cout << "\n\033[1;32mCerrando sesión...\033[0m\n\n";
    } else if (option == 1) {
      std::cout << "\n\033[1;34m=== INVENTARIO ===\033[0m\n";
      inventario->MostrarInventario();
      std::cout << std::endl;
    } else if (option == 2) {
        std::cout << "\n\033[1;34m=== BIBLIOTECAS ===\033[0m\n";
      red->MostrarRed();
    } else if (option == 3) {
      std::cout << "\n\033[1;34m=== BUSCAR LIBRO ===\033[0m\n";
      std::string nombre_libro;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      if (inventario->BuscarLibro(nombre_libro) != nullptr) {
        std::cout << "\033[32m" << "\nEl libro se encuentra en el inventario.\n" << "\033[0m";
        inventario->BuscarLibro(nombre_libro)->MostrarInformacion();
        std::cout << std::endl;
      } else {
        std::cout << "\033[31m" << "\nEl libro NO se encuentra en el inventario.\n\n" << "\033[0m";
      }
    } else if (option == 4) {
      std::cout << "\n\033[1;34m=== AÑADIR LIBRO ===\033[0m\n";
      std::string nombre_libro, nombre_autor;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      std::cout << "Introduzca el nombre del autor: ";
      std::getline(std::cin >> std::ws, nombre_autor);
      Libro* libro = new Libro(nombre_libro, nombre_autor);
      inventario->AgregarLibro(libro);
      std::cout << std::endl;
    } else if (option == 5) {
      std::cout << "\n\033[1;34m=== ELIMINAR LIBRO ===\033[0m\n";
      std::string nombre_libro;
      std::cout << "Introduzca el nombre del libro: ";
      std::getline(std::cin >> std::ws, nombre_libro);
      if (inventario->BuscarLibro(nombre_libro) != nullptr) {
        inventario->EliminarLibro(nombre_libro);
        std::cout << "\033[32m" << "\nEl libro se ha eliminado correctamente.\n\n" << "\033[0m";
      } else {
        std::cout << "\033[31m" << "\nEl libro NO se encuentra en el inventario.\n\n" << "\033[0m";
      }
    } else if (option == 6) {
      std::cout << "\n\033[1;34m=== BUSCAR BIBLIOTECA ===\033[0m\n";
      std::string nombre_biblioteca;
      std::cout << "Introduzca el nombre de la biblioteca: ";
      std::getline(std::cin >> std::ws, nombre_biblioteca);
      if (red->BuscarBiblioteca(nombre_biblioteca) != nullptr) {
        std::cout << "\033[32m" << "\nLa biblioteca se encuentra en la red.\n" << "\033[0m";
        red->BuscarBiblioteca(nombre_biblioteca)->MostrarInformacionBiblioteca();
        std::cout << std::endl;
      } else {
        std::cout << "\033[31m" << "\nLa biblioteca NO se encuentra en la red.\n\n" << "\033[0m";
      }
    } else if (option == 7) {
      std::cout << "\n\033[1;34m=== AÑADIR BILBIOTECA ===\033[0m\n";
      std::string nombre_biblioteca, direccion, telefono, horario;
      std::cout << "Introduzca el nombre de la bilioteca: ";
      std::getline(std::cin >> std::ws, nombre_biblioteca);
      std::cout << "Introduzca la dirección de la biblioteca: ";
      std::getline(std::cin >> std::ws, direccion);
      std::cout << "Introduzca el teléfono de la biblioteca: ";
      std::getline(std::cin >> std::ws, telefono);
      std::cout << "Introduzca el horario de la biblioteca: ";
      std::getline(std::cin >> std::ws, horario);
      Biblioteca* biblioteca = new Biblioteca(nombre_biblioteca, direccion, telefono, horario);
      red->AgregarBiblioteca(biblioteca);
      std::cout << std::endl;
    } else if (option == 8) {
      std::cout << "\n\033[1;34m=== ELIMINAR BIBLIOTECA ===\033[0m\n";
      std::string nombre_biblioteca;
      std::cout << "Introduzca el nombre de la biblioteca: ";
      std::getline(std::cin >> std::ws, nombre_biblioteca);
      if (red->BuscarBiblioteca(nombre_biblioteca) != nullptr) {
        red->EliminarBiblioteca(nombre_biblioteca);
        std::cout << "\033[32m" << "\nLa biblioteca se ha eliminado correctamente.\n\n" << "\033[0m";
      } else {
        std::cout << "\033[31m" << "\nLa biblioteca NO se encuentra en la red\n\n" << "\033[0m";
      }
    } else if(option == 9) {
      std::cout << "¿Seguro que desea eliminar su cuenta?\n";
      std::cout << "Introduzca su usuario y contraseña para confirmar.\n";
      std::string usuario{""};
      std::string contrasena{""};
      std::cin >> usuario;
      std::cin >> contrasena;
      if (usuario == nombreUsuario_ && contrasena == contrasena_) {
        EliminarPersona();
        std::cout << "------------------------------------------------------\n";
        std::cout << "Cuenta eliminada con éxito. Hasta siempre " << nombre_ << "!" << std::endl;
        return;
      } else {
        std::cout << "El nombre de usuario o contraseña no son correctos. Abortando..." << std::endl;
      }
    } else {
      std::cout << "\nOpción inválida. Intente nuevamente.\n";
    }
  } while (option != 0);
  std::cout << std::endl;
}

/**
 * @brief Elimina un administrador
*/
void Administrador::EliminarPersona() {
  std::ifstream archivo_administradores{"administradores_registrados.txt"};
  std::ofstream nuevo_archivo_administradores{"temp.txt"};
  std::string linea_a_comprobar{""};
  std::string nombre_usuario{""};
  bool primero{true};
  if (archivo_administradores.is_open() && nuevo_archivo_administradores.is_open()) {
    while (std::getline(archivo_administradores, linea_a_comprobar)) {
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        nombre_usuario += linea_a_comprobar[i];
      }
      if (nombre_usuario != this->nombreUsuario_) {
        if (!primero) {
          nuevo_archivo_administradores << std::endl;
        }
        nuevo_archivo_administradores << linea_a_comprobar;
        primero = false;
      }
      nombre_usuario = "";
    }
    archivo_administradores.close();
    nuevo_archivo_administradores.close();
    std::rename("temp.txt", "administradores_registrados.txt");
  } else {
    std::cout << "\033[31m" << "Error al abrir los archivos" << "\033[0m" << std::endl;
    exit(EXIT_FAILURE);
  }
}


