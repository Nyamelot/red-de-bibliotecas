
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "libro.h"

class Inventario {
  
  public:
  Inventario(std::ifstream&);
  
  private:

  static bool AbrirInventario(std::ifstream&, std::string);
  static bool CerarInventario(std::ifstream&);

  std::vector<Libro*> inventario_; //Contiene todos los libros en el catalogo
  
};

//Funcion estatica que comprueba la apartura del fichero con el inventario
bool Inventario::AbrirInventario(std::ifstream& fichero_inventario, std::string nombre_fichero) {

  bool apertura_correcta{true};
  fichero_inventario.open(nombre_fichero);
  if (!fichero_inventario.is_open()) {
    apertura_correcta = false;
  }
  
  return apertura_correcta;
}

//Funcion estatica que comprueba el cerrado del fichero con el inventario
bool Inventario::CerarInventario(std::ifstream& fichero_inventario) {
  bool cerrado_correcto{true};
  fichero_inventario.close();
  if (fichero_inventario.is_open()) {
    cerrado_correcto = false;
  }

  return cerrado_correcto;
}

//Constructor clase inventario
Inventario::Inventario(std::ifstream& archivo_inventario) {
  
  std::string linea;
  std::string nombre_libro, nombre_autor, en_prestamo_str, dias_para_devolucion_str;
  int prestamo_int, dias_int;

  //Si se abre el fichero
  if (AbrirInventario(archivo_inventario,"lista_inventario.txt")) {

    //Leemos el fichero por lineas
    while (std::getline(archivo_inventario,linea)) {

      //Creamos un stream de cada linea
      std::stringstream stream(linea); 
      
      //Guardamos el nombre del libro
      std::getline(stream,nombre_libro,'|');
      
      //Guardamos el nombre del autor
      std::getline(stream,nombre_autor, '|');
      
      //Guardamos si esta en prestamo o no, y lo convertimos a entero
      std::getline(stream,en_prestamo_str, '|');
      prestamo_int = std::stoi(en_prestamo_str);
      
      //Guardamos los dias para devolucion y lo convertimos a entero
      std::getline(stream,dias_para_devolucion_str);
      dias_int = std::stoi(dias_para_devolucion_str);
      
      Libro* libro = new Libro(nombre_libro,nombre_autor,prestamo_int,dias_int);
      inventario_.push_back(libro);
    }
  }

  CerarInventario(archivo_inventario);
}

#endif  //INVENTARIO_H

