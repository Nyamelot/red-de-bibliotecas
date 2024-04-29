
#include <iostream>

#include "persona.h"

#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario : public Persona {
 public:
  Usuario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(string, Inventario&) const {}
  Libro PedirPrestamo(Inventario&) override;
  void DevolverPrestamo(Libro*, Inventario&);
  void MainMenu(Inventario*) override;

    
  void buscarLibro() {
    cout << "Buscando libro en el catálogo...\n";
  }

  void hacerReserva() {
    cout << "Haciendo reserva de un libro...\n";
  }

  void devolverLibro() {
  	cout << "Devolviendo un libro...\n";
  }

  void solicitarSalaEstudio() {
    cout << "Solicitando sala de estudio...\n";
  }

};

#endif
