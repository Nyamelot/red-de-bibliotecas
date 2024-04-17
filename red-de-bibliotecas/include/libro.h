
#ifndef LIBRO_H
#define LIBRO_H

#include "inventario.h"

class Libro : public Inventario {

  public:

  Libro(std::string, std::string);
  void PedirPrestamo();


  private:
  std::string nombre_;  // nombre del libro
  std::string nombre_autor_; //nombre autor
  bool en_prestamo_;  // 0 (no esta en prestamo) / 1(está en prestamo)
  int dias_para_devolucion_; // -1 si no esta en prestamo
  
};

#endif