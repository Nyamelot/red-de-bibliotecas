/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Usuario
*/

#include "persona.h"
#include "inventario.h"

#ifndef USUARIO_H
#define USUARIO_H

class Usuario : public Persona {
public:
    Usuario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

    void iniciarSesion() override;
    void registrarse() override;
    bool ConsultarDisponibilidad(string, Inventario&) const {}
    Libro PedirPrestamo(Inventario&) override;
    void DevolverPrestamo(Libro*, Inventario&);

    
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

/*
bool Usuario::ConsultarDisponibilidad(string nombre_libro, Inventario& inventario) {

}
*/

#endif