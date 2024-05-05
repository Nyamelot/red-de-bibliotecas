/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Persona
*/

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

#include "inventario.h"
#include "red_bibliotecas.h"

// Clase base Persona
class Persona {
 protected:
  std::string nombre_;
  std::string apellidos_;
  std::string dni_;
	std::string correoElectronico_;
  std::string rol_;
  std::string contrasena_;
  std::string nombreUsuario_;


 public:
  Persona(std::string nombre, std::string apellidos, std::string dni, std::string correoElectronico, std::string contrasena, std::string nombreUsuario)
  : nombre_(nombre), apellidos_(apellidos), dni_(dni), correoElectronico_(correoElectronico),  contrasena_(contrasena), nombreUsuario_(nombreUsuario){}

  virtual void iniciarSesion();
  virtual void registrarse();
  virtual bool ConsultarDisponibilidad(std::string,Inventario&) const {}
  virtual Libro PedirPrestamo(Inventario&) {}
  virtual void MainMenu(Inventario*, RedBibliotecas*) = 0;
  std::string GetNombrePersona() { return nombre_; }
  virtual void EliminarPersona() = 0;
  virtual void EscribirReseña() = 0;
};

#endif