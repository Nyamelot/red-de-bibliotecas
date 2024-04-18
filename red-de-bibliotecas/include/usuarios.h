/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Clases para identificar a los diferentes perfiles que formarán parte de la infraestructura de la biblioteca
*/

/*#include <string>
#include <vector>

#include "nif.h"

#ifndef USUARIOS_H
#define USUARIOS_H

class Persona {
 public:
  Persona() : nombre_completo_(3) {  }
  ~Persona() {  }
  void virtual PrestamoRecurso() = 0;
  void virtual DevolverRecurso() = 0;
 protected:
  std::vector<std::string> nombre_completo_;
  Nif dni_;
  std::string correo_;
  long telefono_;
  std::string direccion_;
  std::string nombre_usuario_;
  std::string contraseña_;
  // Atributo que indica si el objeto está almacenado en los ficheros o no, esto queda determinado en función de si fue creado mediante el método Registrarse o IniciarSesión
  // Si es true, habrá que escribir la información que almacene en el fichero correspondiente para almacenarla
  bool nuevo_registro_;
};

// Los usuarios se almacenarán según el siguiente esquema:
// Nombre_de_usuario Contraseña Nombre Apellido1 Apellido2 DNI Correo Telefono Libros_reservados
class Usuario : public Persona {
 public:
  Usuario() : Persona() {  }
  virtual void PrestamoRecurso() {  }
  virtual void DevolverRecurso() {  }
 protected:
  //std::vector<Libro> prestamos_;
};

class Bibliotecario : public Persona {
 public:
  Bibliotecario() : Persona() {  }
  virtual void PrestamoRecurso() {  }
  virtual void DevolverRecurso() {  }
  protected:
};

#endif*/