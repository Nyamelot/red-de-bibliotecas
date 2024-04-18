/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de diferentes funciones de utilidad para el programa
*/

#include "inventario.h"
#include "usuarios.h"

std::optional<Persona*> IniciarSesion(std::string nombre_usuario, std::string contraseña) {
  // no sé si esta línea seguirá funcionando si el fichero no se encuentra en el mismo directorio que el ejecutable
  std::ifstream fichero_usuarios{"usuarios_registrados.txt"};
  std::string nombre_a_comprobar{""};
  std::string contraseña_a_comprobar{""};
  int numero_intentos{0};
  Persona* persona_a_retornar = nullptr;
  std::string linea_a_comprobar{""};
  while (std::getline(fichero_usuarios, linea_a_comprobar)) {
    nombre_a_comprobar = "";
    contraseña_a_comprobar = "";
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      nombre_a_comprobar += linea_a_comprobar[i];
    }
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      contraseña_a_comprobar += linea_a_comprobar[i];
    }
    if (nombre_usuario == nombre_a_comprobar) {
      while (contraseña != contraseña_a_comprobar && numero_intentos < 5) {
        std::cout << "error. La contraseña no es correta. Inténtelo de nuevo" << std::endl;
        std::cin >> contraseña;
        ++numero_intentos;
      }
      if (numero_intentos == 5) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        return std::nullopt;
      }
      persona_a_retornar = new Usuario();
      return persona_a_retornar;
    }
  }
  fichero_usuarios.close();
  numero_intentos = 0;
  std::ifstream fichero_bibliotecarios{"bibliotecarios_registrados.txt"};
  while (std::getline(fichero_bibliotecarios, linea_a_comprobar)) {
    nombre_a_comprobar = "";
    contraseña_a_comprobar = "";
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      nombre_a_comprobar += linea_a_comprobar[i];
    }
    for (int i{0}; linea_a_comprobar[i] != ' '; ++i) {
      contraseña_a_comprobar += linea_a_comprobar[i];
    }
    if (nombre_usuario == nombre_a_comprobar) {
      while (contraseña != contraseña_a_comprobar && numero_intentos < 5) {
        std::cout << "error. La contraseña no es correta. Inténtelo de nuevo" << std::endl;
        std::cin >> contraseña;
        ++numero_intentos;
      }
      if (numero_intentos == 5) {
        std::cout << "error. Se ha exedido el máximo número de intentos." << std::endl;
        return std::nullopt;
      }
      persona_a_retornar = new Usuario();
      return persona_a_retornar;
    }
  }
  std::cout << "error. No se ha encontrado el usuario." << std::endl;
  fichero_bibliotecarios.close();
  return std::nullopt;
}

//Funcion que comprueba la apertura del fichero que contiene el inventario
bool AbrirInventario(std::ifstream& archivo_inventario, std::string nombre_archivo_inventario) {
  
  bool apertura_correcta{true};
  archivo_inventario.open(nombre_archivo_inventario);
  if (!archivo_inventario.is_open()) {
    apertura_correcta = false;
  }

  return apertura_correcta;
}

//Funcion que comprueba si el archivo se ha cerrado correctamente
bool CerarInventario(std::ifstream& archivo_inventario) {

  bool cerrar_correcto{true};
  archivo_inventario.close();
  if (archivo_inventario.is_open()) {
    cerrar_correcto = false;
  }

  return cerrar_correcto;
}