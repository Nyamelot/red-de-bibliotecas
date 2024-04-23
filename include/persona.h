/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Persona
*/

#include <iostream>
#include <string>

#include "inventario.h"

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

// Clase base Persona
class Persona {
 protected:
  string nombre_;
  string apellidos_;
  string dni_;
	string correoElectronico_;
  string rol_;
  string contrasena_;
  string nombreUsuario_;


 public:
  Persona(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
  : nombre_(nombre), apellidos_(apellidos), dni_(dni), correoElectronico_(correoElectronico),  contrasena_(contrasena), nombreUsuario_(nombreUsuario){}

  virtual void iniciarSesion();
  virtual void registrarse();
  virtual bool ConsultarDisponibilidad(string,Inventario&) const {}
  virtual Libro PedirPrestamo(Inventario&) {}
  virtual void MainMenu() = 0;
};

#endif