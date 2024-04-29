
#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <iostream>

#include "persona.h"

class Administrador : public Persona {
 public:
  Administrador(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico,contrasena, nombreUsuario ) {}
  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(string,Inventario&) const {}
  void MainMenu(Inventario*, RedBibliotecas*) override;

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
