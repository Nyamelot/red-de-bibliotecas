/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @author Diego Hernández Chico
 * @date 16 Mar 2024
 * CORREO: alu0101572062@ull.edu.es
 * @brief Fichero con la declaración de la clase de Nif
*/

#ifndef NIF_H
#define NIF_H

#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>


class Nif {
  public:
  Nif();
  Nif(long valor_nif);
  ~Nif() {  };
  operator long() const { return valor_nif_; }
  int operator%(int) const;
  void operator=(int);
  private:
  long valor_nif_;
};

#endif