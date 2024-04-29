/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 29 Abr 2024
 * @brief Programa para dar soporte a una red de bibliotecas
*/
#include <iostream>
#include <string>

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

class Biblioteca {
 private:
  std::string nombre_;
  std::string direccion_;
  std::string telefono_;
  std::string horario_;

 public:
  Biblioteca(std::string nombre, std::string direccion, std::string telefono, std::string horario) : nombre_{nombre}, direccion_{direccion}, telefono_{telefono}, horario_{horario} {};
  std::string GetNombre() const { return nombre_; }
  std::string GetDireccion() const { return direccion_; }
  std::string GetTelefono() const { return telefono_;}
  std::string GetHorario() const { return horario_; }
  void MostrarInformacionBiblioteca() {
    std::cout << "Nombre:      " << GetNombre() << std::endl;
    std::cout << "  Dirección: " << GetDireccion() << std::endl;
    std::cout << "  Teléfono:  " << GetTelefono() << std::endl;
    std::cout << "  Horario:   " << GetHorario() << std::endl;
  }
  
};

#endif  //BIBLIOTECA_H