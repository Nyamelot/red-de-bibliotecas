/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Libro
*/

#include <string>
#include <iostream>

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
 public:
  Libro(std::string nombre, std::string autor, int en_prestamo , int dias_devolucion) : nombre_(nombre), nombre_autor_(autor), en_prestamo_(en_prestamo), dias_para_devolucion_(dias_devolucion)  {}
  Libro(std::string nombre,std::string autor) : nombre_(nombre), nombre_autor_(autor), en_prestamo_(0),dias_para_devolucion_(-1) {}
  Libro(const Libro&) {}
  void PonerEnPrestamo();
  Libro GetLibro() {}
  std::string GetNombre() { return nombre_; }
  std::string GetAutor() { return nombre_autor_; }
  bool GetEnPrestamo() { return en_prestamo_; }
  int GetDiasParaDevolucion() { return dias_para_devolucion_; }
  void MostrarInformacion();

 private:

  void ActualizarInventario() {}

  std::string nombre_;  // nombre del libro
  std::string nombre_autor_; //nombre autor
  bool en_prestamo_;  // 0 (no esta en prestamo) / 1(está en prestamo)
  int dias_para_devolucion_; // -1 si no esta en prestamo (No hay que devolverlo, por lo que no hace falta marcar fecha)
  
};

#endif