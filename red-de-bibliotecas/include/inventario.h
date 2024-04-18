
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tools.h"
#include "libro.h"

class Inventario {
  
  public:
  Inventario(std::ifstream&);
  
  private:
  std::vector<Libro*> inventario_; //Contiene todos los libros en el catalogo
  
};

Inventario::Inventario(std::ifstream& archivo_inventario) {
  
  if (AbrirInventario(archivo_inventario,std::string nombre{"lista_inventario.txt"})) {
    
  }
  CerarInventario(archivo_inventario);
}

#endif  //INVENTARIO_H

