
#include <iostream>

#include "personas/usuario.h"

void Usuario::iniciarSesion() {
  std::cout << "=== Inicio de sesión como usuario ===" << std::endl;
  Persona::iniciarSesion();
}

void Usuario::registrarse() {
  std::cout << "=== Registro de usuario ===" << std::endl;
  Persona::registrarse();
}

Libro Usuario::PedirPrestamo(Inventario& inventario) {
  std::cout << "=== Pedir préstamo === " << std::endl;
  std::cout << "Introduzca el libro que desea" << std::endl;

  std::string nombreLibro{""};
  std::string nombreAutor{""};
  std::cin >> nombreLibro;
    
  std::cout << "Introduzca el autor del libro que desea" << std::endl;
  std::cin >> nombreAutor;

  if (ConsultarDisponibilidad(nombreLibro,inventario)) {
    std::cout << "Libro disponible" << std::endl;
    Libro libro(nombreLibro, nombreAutor);
    return libro;
  } else {
    std::cout << "El libro no se encuentra disponible" << std::endl;
    exit(EXIT_FAILURE);
  }
}

//Devolver prestamo 
void Usuario::DevolverPrestamo(Libro* libro, Inventario& inventario) {
  std::cout << "=== Devolver préstamo ===" << std::endl;
  std::cout << "Introduzca el libro que desea devolver" << std::endl;

  std::string nombreLibro, nombreAutor;
  std::cin >> nombreLibro;
    
  std::cout << "Introduzca el autor del libro que desea devolver" << std::endl;
  std::cin >> nombreAutor;

  inventario.AgregarLibro(libro);

    std::cout << "Libro devuelto con éxito" << std::endl;

}

void Usuario::MainMenu(Inventario* inventario, RedBibliotecas* red) {
  int option;
  do {
    std::cout << "\n\033[1;33m=== MENÚ PRINCIPAL DE USUARIO ===\033[0m\n";
    std::cout << "  [0] Cerrar Sesión\n";
    std::cout << "  [1] Mostrar Inventario\n";
    std::cout << "  [2] Mostrar Bibliotecas\n";
    std::cout << "  [3] Buscar un libro\n";
    std::cout << "  [4] Buscar una biblioteca\n";
    std::cout << "  [5] Pedir préstamo\n";
    std::cout << "  [6] Devolver Préstamos\n";
    std::cout << "  [7] Eliminar la cuenta\n";
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
    } else if (option == 5) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
      // std::ifstream inventario("lista_inventario.txt");
      // Inventario inventario_obj(inventario);            
      // this->PedirPrestamo(inventario_obj);
    } else if (option == 6) {
      std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
        // std::ifstream inventario("lista_inventario.txt");
        // Inventario inventario_obj(inventario);
    } else if (option == 7) {
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
      std::cout << "\n\033[31mOpción inválida. Intente nuevamente.\033[0m\n";
    }
    } while (option != 0);
}

/**
 * @brief Elimina un usuario
*/
void Usuario::EliminarPersona() {
  std::ifstream archivo_usuario{"usuarios_registrados.txt"};
  std::ofstream nuevo_archivo_usuario{"temp.txt"};
  std::string linea_a_comprobar{""};
  std::string nombre_usuario{""};
  bool primero{true};
  if (archivo_usuario.is_open() && nuevo_archivo_usuario.is_open()) {
    while (std::getline(archivo_usuario, linea_a_comprobar)) {
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        nombre_usuario += linea_a_comprobar[i];
      }
      if (nombre_usuario != this->nombreUsuario_) {
        if (!primero) {
          nuevo_archivo_usuario << std::endl;
        }
        nuevo_archivo_usuario << linea_a_comprobar;
        primero = false;
      }
      nombre_usuario = "";
    }
    archivo_usuario.close();
    nuevo_archivo_usuario.close();
    std::rename("temp.txt", "usuarios_registrados.txt");
  } else {
    std::cout << "\033[31m" << "Error al abrir los archivos" << "\033[0m" << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Usuario::EscribirReseña() {
  std::ofstream archivo_reseñas{"data/reseñas_registradas.txt"}; //la reseña se escribe en el documento "reseñas_registradas.txt"
  int valoracion = -1;
  while (valoracion > 5 || valoracion < 1){
    std::cout << "Valore del 1 al 5 su experiencia" << std::endl;
    std::cin >> valoracion;
    if(valoracion > 5 || valoracion < 1) {
    std::cerr << "Error, valoracion incorrecta, pruebe un numero entre 1 y 5" << std::endl;
    }
  }

  archivo_reseñas << this->nombre_ << " " << this->apellidos_ << ":\n"; //metemos su nombre y su puntuacion
  archivo_reseñas << valoracion << std::endl;

  char descripcion{'x'}; //para aportar si el usuario quiere poner una descripcion
  while (descripcion != 'n' && descripcion != 'y') {
    std::cout << "¿Quiere aportar una descripción a su reseña? [y/n]" << std::endl;
    std::cin >> descripcion;
    if (descripcion != 'n' && descripcion != 'y') {
      std::cerr << "Error, respuesta incorrecta, prueba entre y/n" << std::endl;
    }
  }
  std::string reseña;
  std::getline(std::cin, reseña); //Se le pide por linea de comandos la reseña al usuario
  archivo_reseñas << reseña << std::endl;
}
