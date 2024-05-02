/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Persona
*/

#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <iostream>

#include "persona.h"

class Administrador : public Persona {
 public:
  Administrador(std::string nombre, std::string apellidos, std::string dni, std::string correoElectronico, std::string contrasena, std::string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico,contrasena, nombreUsuario ) {}
  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(std::string,Inventario&) const {}
  void MainMenu(Inventario*, RedBibliotecas*) override;
  virtual void EliminarPersona();

  // void gestionarUsuarios() {
  //   std::cout << "Gestionando usuarios del sistema...\n";
  // }

  // void anadirNuevaBiblioteca() {
  //   std::cout << "Añadiendo nueva biblioteca a la red...\n";
  // }

  // void gestionarServiciosOnline() {
  // 	std::cout << "Gestionando servicios online...\n";
  // }

  // void gestionarMedidasSeguridad() {
  //   std::cout << "Gestionando medidas de seguridad...\n";
  // }

  // void gestionarUsuariosSistema() {
  // 	std::cout << "Gestionando usuarios del sistema...\n";
  // }

};

#endif
