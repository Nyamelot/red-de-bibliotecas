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

Inventario* InicializarInventario() {
  std::ifstream archivo_inventario;
  Inventario* inventario = new Inventario(archivo_inventario);
  return inventario;
}

RedBibliotecas* InicializarRed() {
  std::ifstream archivo_inventario;
  RedBibliotecas* red = new RedBibliotecas(archivo_inventario);
  return red;
}

void LoginMenu(Inventario* inventario, RedBibliotecas* red) {
  std::cout << "\033[32m" << "BIENVENIDO A LA SEDE ELECTRONICA DE LA RED DE BIBLIOTECAS!\n\n" << "\033[0m";

  int option;
  do {
    std::cout << "\033[1;33m=== MENÚ INICIAL ===\033[0m\n";
    std::cout << "  [0] Salir\n";
    std::cout << "  [1] Iniciar sesión\n";
    std::cout << "  [2] Registrarse\n";
    std::cout << "  Introduzca una opción: ";
    std::cin >> option;
    if (option < 0 || option > 4) {
      std::cout << "\033[31m" << "\nerror. Opción no válida. Intentelo de nuevo\n\n" << "\033[0m";
    }
    if (option == 1) {
      std::cout << "\n\033[1;33m=== INICIAR SESIÓN ===\033[0m\n";
      std::string usuario{""};
      std::string contrasena{""};
      std::cout << "Introduzca su nombre de usuario: ";
      std::cin >> usuario;
      std::cout << "Introduzca su contraseña: ";
      std::cin >> contrasena;
      ControladorUsuarios controlador;
      Persona* persona = controlador.IniciarSesion(usuario, contrasena);
      if (persona != nullptr) {
        std::cout << "\033[32m" << "\nBIENVENIDO DE NUEVO " << persona->GetNombrePersona() << "!\n" << "\033[0m";
        persona->MainMenu(inventario, red);
        delete persona;
        persona = nullptr;
      } else {
        std::cout << "El usuario o la contraseña no son correctos. Intentelo de nuevo.\n";
      }
    } else if (option == 2) {
      std::cout << "\n\033[1;33m=== REGISTRARSE ===\033[0m\n";
      ControladorUsuarios controlador;
      Persona* nuevo_usuario = nullptr;
      while (nuevo_usuario == nullptr) {
        nuevo_usuario = controlador.Registrarse();
      }
      std::cout << "\033[32m" << "\nBIENVENIDO " << nuevo_usuario->GetNombrePersona() << "!\n" << "\033[0m";
      nuevo_usuario->MainMenu(inventario, red);
      delete nuevo_usuario;
      nuevo_usuario = nullptr;
    }
  } while (option != 0);
  std::cout << "\033[32m" << "\nSaliendo de la sede...\n" << "\033[0m";
}

int main() {
  Inventario *inventario = InicializarInventario();
  RedBibliotecas *red = InicializarRed();
  LoginMenu(inventario, red);
  return 0;
}