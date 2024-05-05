/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Persona
*/

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <string>

#include "persona.h"

class Usuario : public Persona {
 public:
  Usuario(std::string nombre, std::string apellidos, std::string dni, std::string correoElectronico, std::string contrasena, std::string nombreUsuario)
  : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

  void iniciarSesion() override;
  void registrarse() override;
  bool ConsultarDisponibilidad(std::string, Inventario&) const;
  Libro* PedirPrestamo(Inventario&) override;
  void RegistrarPrestamo(Libro* prestamo_a_registrar);
  void DevolverPrestamo(Libro*, Inventario&);
  void MainMenu(Inventario*, RedBibliotecas*) override;
  virtual void EliminarPersona();

    
  // void buscarLibro() {
  //   cout << "Buscando libro en el catálogo...\n";
  // }

  // void hacerReserva() {
  //   cout << "Haciendo reserva de un libro...\n";
  // }

  // void devolverLibro() {
  // 	cout << "Devolviendo un libro...\n";
  // }

  // void solicitarSalaEstudio() {
  //   cout << "Solicitando sala de estudio...\n";
  // }

};

#endif
