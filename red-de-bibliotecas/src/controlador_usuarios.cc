/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de diferentes funciones de utilidad para el programa
*/

#include <iostream>
#include <fstream>

#include "controlador_usuarios.h"
#include "persona.h"
#include "usuario.h"
#include "bibliotecario.h"
#include "administrador.h"

/**
 * @brief Inicia la sesión del usuario que se ha pasado como argumento
 * 
 * @param Nombre del usuario y contraseña del mismo
 * @return Puntero al usuario creado o nullptr si no se ha encontrado al usuario
*/
Persona* ControladorUsuarios::IniciarSesion(std::string nombre_usuario, std::string contrasena) {
  Persona* usuario_a_retornar = nullptr;
  usuario_a_retornar = BuscaUsuario(nombre_usuario, contrasena);
  if (usuario_a_retornar == nullptr) {
    usuario_a_retornar = BuscaBibliotecario(nombre_usuario, contrasena);
  }
  if (usuario_a_retornar == nullptr) {
    usuario_a_retornar = BuscaAdmin(nombre_usuario, contrasena);
  }
  if (usuario_a_retornar == nullptr){
    std::cout << "error. No se ha encontrado el usuario." << std::endl;
    return nullptr;
  }
  return usuario_a_retornar;
}

/**
 * @brief Busca un nombre de usuario y una contraseña en el fichero "usuarios_registrados.txt"
 * 
 * @param Nombre de usuario y contraseña
 * @return nullptr si no se ha encontrado al usuario o un puntero a persona si se ha encontrado.
*/
Persona* ControladorUsuarios::BuscaUsuario(std::string nombre_usuario, std::string contrasena) {
  std::ifstream fichero_usuarios{"usuarios_registrados.txt"};
  std::string nombre_a_comprobar{""};
  std::string contrasena_a_comprobar{""};
  std::string nombre{""};
  std::string apellido{""};
  std::string dni{""};
  std::string correo{""};
  int numero_intentos{0};
  Persona* persona_a_retornar = nullptr;
  std::string linea_a_comprobar{""};
  while (std::getline(fichero_usuarios, linea_a_comprobar)) {
    nombre_a_comprobar = "";
    contrasena_a_comprobar = "";
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      nombre_a_comprobar += linea_a_comprobar[i];
    }
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      contrasena_a_comprobar += linea_a_comprobar[i];
    }
    if (nombre_usuario == nombre_a_comprobar) {
      while (contrasena != contrasena_a_comprobar && numero_intentos < 5) {
        std::cout << "error. La contraseña no es correta. Inténtelo de nuevo" << std::endl;
        std::cin >> contrasena;
        ++numero_intentos;
      }
      if (numero_intentos == 5) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        fichero_usuarios.close();
        return nullptr;
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        nombre += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        apellido += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        dni += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        correo += linea_a_comprobar[i];
      }
      persona_a_retornar = new Usuario(nombre, apellido, dni, correo, contrasena_a_comprobar, nombre_a_comprobar);
      fichero_usuarios.close();
      return persona_a_retornar;
    }
  }
  fichero_usuarios.close();  
  return nullptr;
}

/**
 * @brief Busca un nombre de usuario y una contraseña en el fichero "bibliotecarios_registrados.txt"
 * 
 * @param Nombre de usuario y contraseña
 * @return nullptr si no se ha encontrado al bibliotecario o un puntero a persona si se ha encontrado.
*/
Persona* ControladorUsuarios::BuscaBibliotecario(std::string nombre_usuario, std::string contrasena) {
  std::ifstream fichero_bibliotecarios{"bibliotecarios_registrados.txt"};
  std::string nombre_a_comprobar{""};
  std::string contrasena_a_comprobar{""};
  std::string nombre{""};
  std::string apellido{""};
  std::string dni{""};
  std::string correo{""};
  int numero_intentos{0};
  Persona* persona_a_retornar = nullptr;
  std::string linea_a_comprobar{""};  
  while (std::getline(fichero_bibliotecarios, linea_a_comprobar)) {
    nombre_a_comprobar = "";
    contrasena_a_comprobar = "";
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      nombre_a_comprobar += linea_a_comprobar[i];
    }
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      contrasena_a_comprobar += linea_a_comprobar[i];
    }
    if (nombre_usuario == nombre_a_comprobar) {
      while (contrasena != contrasena_a_comprobar && numero_intentos < 5) {
        std::cout << "error. La contraseña no es correta. Inténtelo de nuevo" << std::endl;
        std::cin >> contrasena;
        ++numero_intentos;
      }
      if (numero_intentos == 5) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        fichero_bibliotecarios.close();
        return nullptr;
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        nombre += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        apellido += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        dni += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        correo += linea_a_comprobar[i];
      }
      persona_a_retornar = new Bibliotecario(nombre, apellido, dni, correo, contrasena_a_comprobar, nombre_a_comprobar);
      fichero_bibliotecarios.close();
      return persona_a_retornar;
    }
  }
  fichero_bibliotecarios.close();
  return nullptr;
}

/**
 * @brief Busca un nombre de usuario y una contraseña en el fichero "administradores_registrados.txt"
 * 
 * @param Nombre de usuario y contraseña
 * @return nullptr si no se ha encontrado al administrador o un puntero a persona si se ha encontrado.
*/
Persona* ControladorUsuarios::BuscaAdmin(std::string nombre_usuario, std::string contrasena) {
  std::ifstream fichero_administradores{"administradores_registrados.txt"};
  std::string nombre_a_comprobar{""};
  std::string contrasena_a_comprobar{""};
  std::string nombre{""};
  std::string apellido{""};
  std::string dni{""};
  std::string correo{""};
  int numero_intentos{0};
  Persona* persona_a_retornar = nullptr;
  std::string linea_a_comprobar{""};  
  while (std::getline(fichero_administradores, linea_a_comprobar)) {
    nombre_a_comprobar = "";
    contrasena_a_comprobar = "";
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      nombre_a_comprobar += linea_a_comprobar[i];
    }
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      contrasena_a_comprobar += linea_a_comprobar[i];
    }
    if (nombre_usuario == nombre_a_comprobar) {
      while (contrasena != contrasena_a_comprobar && numero_intentos < 5) {
        std::cout << "error. La contraseña no es correta. Inténtelo de nuevo" << std::endl;
        std::cin >> contrasena;
        ++numero_intentos;
      }
      if (numero_intentos == 5) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        fichero_administradores.close();
        return nullptr;
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        nombre += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        apellido += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        dni += linea_a_comprobar[i];
      }
      for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
        correo += linea_a_comprobar[i];
      }
      persona_a_retornar = new Administrador(nombre, apellido, dni, correo, contrasena_a_comprobar, nombre_a_comprobar);
      fichero_administradores.close();
      return persona_a_retornar;
    }
  }
  fichero_administradores.close();
  return nullptr;
}

/**
 * @brief Lleva a cabo la acción de registrarse en el sistema
 * 
 * @return Objeto registrado para usar durante la sesión
*/
Persona* ControladorUsuarios::Registrarse() {
  int tipo_registro{0};
  std::string nombre_a_comprobar{""};
  std::string contrasena_a_comprobar{""};
  Persona* usuario_a_retornar = nullptr;
  std::cout << "¿Cuál es tu perfil? (Introduce el número correspondiente)." << std::endl;
  std::cout << "  [0] Usuario." << std::endl;
  std::cout << "  [1] Bibliotecario." << std::endl;
  std::cout << "  [2] Administrador." << std::endl;
  std::cin >> tipo_registro;
  switch (tipo_registro) {
    case 0:
      usuario_a_retornar = RegistrarUsuario();
      return usuario_a_retornar;
      break;
    case 1:
      std::cout << "Introduce las creedenciales de un bibliotecario o un administrador para continuar." << std::endl;
      std::cout << "Nombre de usuario: ";
      std::cin >> nombre_a_comprobar;
      std::cout << std::endl << "Contraseña: ";
      std::cin >> contrasena_a_comprobar;
      if (BuscaBibliotecario(nombre_a_comprobar, contrasena_a_comprobar) == nullptr && BuscaAdmin(nombre_a_comprobar, contrasena_a_comprobar) == nullptr) {
        std::cout << "error. No se ha introducido un usuario válido." << std::endl;
        return nullptr;
      }
      usuario_a_retornar = RegistrarBibliotecario();
      break;
    case 2:
      std::cout << "Introduce las creedenciales de un administrador para continuar." << std::endl;
      std::cout << "Nombre de usuario: ";
      std::cin >> nombre_a_comprobar;
      std::cout << std::endl << "Contraseña: ";
      std::cin >> contrasena_a_comprobar;
      if (BuscaAdmin(nombre_a_comprobar, contrasena_a_comprobar) == nullptr) {
        std::cout << "error. No se ha introducido un usuario válido." << std::endl;
        return nullptr;
      }
      usuario_a_retornar = RegistrarAdmin();
      break;
    default:
      std::cout << "error. No se ha elegido una opción válida." << std::endl;
      return nullptr;
  }
  return usuario_a_retornar;
}

/**
 * @brief Registra a un usuario 
 * 
 * @return Puntero al usuario creado
*/
Persona* ControladorUsuarios::RegistrarUsuario() {
  // Inicializamos variables de apoyo
  std::ofstream fichero_usuarios{"usuarios_registrados.txt", std::ios::app};
  std::string nombre;
  std::string apellido;
  std::string dni;
  std::string correo;
  std::string contrasena;
  std::string nombre_usuario;
  // Obtenemos los datos
  std::cout << "Rellene los siguientes campos para completar el registro:" << std::endl;
  std::cout << "Nombre: ";
  std::cin >> nombre;
  std::cout << std::endl << "Apellido: ";
  std::cin >> apellido;
  std::cout << std::endl << "Dni: ";
  std::cin >> dni;
  std::cout << std::endl << "Correo: ";
  std::cin >> correo;
  std::cout << std::endl << "Nombre de usuario: ";
  std::cin >> nombre_usuario;
  std::cout << std::endl << "Contraseña: ";
  std::cin >> contrasena;
  // Creamos el objeto
  Persona* usuario_a_registrar = new Usuario(nombre, apellido, dni, correo, contrasena, nombre_usuario);
  // Introducimos la información en el fichero
  fichero_usuarios << nombre_usuario << " " << contrasena << " " << nombre << " " << apellido << " " << dni << " " << correo << std::endl;
  return usuario_a_registrar;
}

/**
 * @brief Registra a un bibliotecario
 * 
 * @return Puntero al bibliotecario creado
*/
Persona* ControladorUsuarios::RegistrarBibliotecario() {
  // Inicializamos variables de apoyo
  std::ofstream fichero_usuarios{"bibliotecarios_registrados.txt", std::ios::app};
  std::string nombre;
  std::string apellido;
  std::string dni;
  std::string correo;
  std::string contrasena;
  std::string nombre_usuario;
  // Obtenemos los datos
  std::cout << "Rellene los siguientes campos para completar el registro:" << std::endl;
  std::cout << "Nombre: ";
  std::cin >> nombre;
  std::cout << std::endl << "Apellido: ";
  std::cin >> apellido;
  std::cout << std::endl << "Dni: ";
  std::cin >> dni;
  std::cout << std::endl << "Correo: ";
  std::cin >> correo;
  std::cout << std::endl << "Nombre de usuario: ";
  std::cin >> nombre_usuario;
  std::cout << std::endl << "Contraseña: ";
  std::cin >> contrasena;
  // Creamos el objeto
  Persona* usuario_a_registrar = new Bibliotecario(nombre, apellido, dni, correo, contrasena, nombre_usuario);
  // Introducimos la información en el fichero
  fichero_usuarios << nombre_usuario << " " << contrasena << " " << nombre << " " << apellido << " " << dni << " " << correo << std::endl;
  return usuario_a_registrar;
}

/**
 * @brief Registra a un Administrador
 * 
 * @return Puntero al administrador creado
*/
Persona* ControladorUsuarios::RegistrarAdmin() {
  // Inicializamos variables de apoyo
  std::ofstream fichero_usuarios{"administradores_registrados.txt", std::ios::app};
  std::string nombre;
  std::string apellido;
  std::string dni;
  std::string correo;
  std::string contrasena;
  std::string nombre_usuario;
  // Obtenemos los datos
  std::cout << "Rellene los siguientes campos para completar el registro:" << std::endl;
  std::cout << "Nombre: ";
  std::cin >> nombre;
  std::cout << std::endl << "Apellido: ";
  std::cin >> apellido;
  std::cout << std::endl << "Dni: ";
  std::cin >> dni;
  std::cout << std::endl << "Correo: ";
  std::cin >> correo;
  std::cout << std::endl << "Nombre de usuario: ";
  std::cin >> nombre_usuario;
  std::cout << std::endl << "Contraseña: ";
  std::cin >> contrasena;
  // Creamos el objeto
  Persona* usuario_a_registrar = new Administrador(nombre, apellido, dni, correo, contrasena, nombre_usuario);
  // Introducimos la información en el fichero
  fichero_usuarios << nombre_usuario << " " << contrasena << " " << nombre << " " << apellido << " " << dni << " " << correo << std::endl;
  return usuario_a_registrar;
}