
#ifndef BIBLIOTECARIO_H_
#define BIBLIOTECARIO_H_

#include <iostream>

#include "persona.h"

class Bibliotecario : public Persona {
 public:
 	Bibliotecario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
 	: Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

 	void iniciarSesion() override;
 	void registrarse() override;
 	void MainMenu(Inventario*, RedBibliotecas*) override;
 	void ComprobarCatalogo() {}
 	bool ConsultarDisponibilidad(string,Inventario&) const {}
  virtual void EliminarPersona();


 	// void ayudarUsuario() {
  //   std::cout << "Asistiendo a un usuario...\n";
  // }

  // void anadirLibroCatalogo() {
  //   std::cout << "Añadiendo libro al catálogo...\n";
  // }

  // void eliminarLibroCatalogo() {
  // 	std::cout << "Eliminando libro del catálogo...\n";
  // }

  // void gestionarPrestamos() {
  //   std::cout << "Gestionando préstamos...\n";
  // }

  //   void gestionarMultas() {
  //     std::cout << "Gestionando multas...\n";
  //   }

};

#endif
