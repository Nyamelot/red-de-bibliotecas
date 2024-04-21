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


class Usuario : public Persona {
 public:
  Usuario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(string, Inventario&) const {}
  Libro PedirPrestamo(Inventario&) override;
  void DevolverPrestamo(Libro*, Inventario&);
  void MainMenu() override;

    
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


class Bibliotecario : public Persona {
 public:
 	Bibliotecario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
 	: Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

 	void iniciarSesion() override;
 	void registrarse() override;
 	void MainMenu() override;
 	void ComprobarCatalogo() {}
 	bool ConsultarDisponibilidad(string,Inventario&) const {}

 	void ayudarUsuario() {
    cout << "Asistiendo a un usuario...\n";
  }

  void anadirLibroCatalogo() {
    cout << "Añadiendo libro al catálogo...\n";
  }

  void eliminarLibroCatalogo() {
  	cout << "Eliminando libro del catálogo...\n";
  }

  void gestionarPrestamos() {
    cout << "Gestionando préstamos...\n";
  }

    void gestionarMultas() {
        cout << "Gestionando multas...\n";
    }

};


class Administrador : public Persona {
 public:
  Administrador(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico,contrasena, nombreUsuario ) {}
  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(string,Inventario&) const {}
  void MainMenu() override;  
  void gestionarUsuarios() {
    cout << "Gestionando usuarios del sistema...\n";
  }

  void anadirNuevaBiblioteca() {
    cout << "Añadiendo nueva biblioteca a la red...\n";
  }

  void gestionarServiciosOnline() {
  	cout << "Gestionando servicios online...\n";
  }

  void gestionarMedidasSeguridad() {
    cout << "Gestionando medidas de seguridad...\n";
  }

  void gestionarUsuariosSistema() {
  	cout << "Gestionando usuarios del sistema...\n";
  }

};

#endif