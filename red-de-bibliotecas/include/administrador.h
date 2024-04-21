/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Administrador
*/

#include "persona.h"
#include "inventario.h"

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Persona {
public:
    Administrador(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico,contrasena, nombreUsuario ) {}


    void iniciarSesion() override;
    void registrarse() override;
    bool ConsultarDisponibilidad(string,Inventario&) const {}
    
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