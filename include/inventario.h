/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Inventario
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "libro.h"

#ifndef INVENTARIO_H
#define INVENTARIO_H

class Inventario {
  
  public:
  Inventario(std::ifstream&);
  std::vector<Libro*> AgregarLibro(Libro*);
  
  private:

  static bool AbrirInventario(std::ifstream&, std::string);
  static bool CerarInventario(std::ifstream&);
  //agregar libro al inventario
  

  std::vector<Libro*> inventario_; //Contiene todos los libros en el catalogo
  
};

#endif  //INVENTARIO_H