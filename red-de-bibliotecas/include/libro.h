
#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>

class Libro {

  public:

  Libro(std::string nombre, std::string autor, int en_prestamo, int dias_devolucion) : nombre_(nombre), nombre_autor_(autor), en_prestamo_(en_prestamo), dias_para_devolucion_(dias_devolucion)  {}
  Libro(std::string nombre,std::string autor) : nombre_(nombre), nombre_autor_(autor), en_prestamo_(0),dias_para_devolucion_(-1) {}
  Libro(const Libro&);
  void PonerEnPrestamo(std::string);
  Libro GetLibro();
  private:

  void ActualizarInventario();

  std::string nombre_;  // nombre del libro
  std::string nombre_autor_; //nombre autor
  std::string nombre_propietario_; // Nombre del usuario que tiene el libro en prestamo
  bool en_prestamo_;  // 0 (no esta en prestamo) / 1(está en prestamo)
  int dias_para_devolucion_; // -1 si no esta en prestamo (No hay que devolverlo, por lo que no hace falta marcar fecha)
  
};

void Libro::PonerEnPrestamo(std::string nombre_usuario) {
  nombre_propietario_ = nombre_usuario;
  en_prestamo_ = true;
  dias_para_devolucion_ = 30;

}

#endif