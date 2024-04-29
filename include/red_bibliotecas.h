/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 29 Abr 2024
 * @brief Programa para dar soporte a una red de bibliotecas
*/
#ifndef RED_BIBLIOTECAS_H
#define RED_BIBLIOTECAS_H

#include "biblioteca.h"
#include <vector>
#include <fstream>
#include <sstream>

class RedBibliotecas {
 private: 
  std::vector<Biblioteca*> bibliotecas_;

 public:
  RedBibliotecas(std::ifstream& archivo_bibliotecas);
  bool AbrirListado(std::ifstream& fichero_bibliotecas, std::string nombre_fichero);
  bool CerarListado(std::ifstream& fichero_bibliotecas);
  void MostrarRed();
  std::vector<Biblioteca*> AgregarBiblioteca(Biblioteca* biblioteca);
  Biblioteca* BuscarBiblioteca(std::string nombre_biblioteca);
  void EliminarBiblioteca(std::string nombre_biblioteca);
};

#endif  //RED_BIBLIOTECAS_H