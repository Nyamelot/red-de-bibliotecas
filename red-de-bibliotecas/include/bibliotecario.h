/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la declaración de la clase Bibliotecario
*/

#include "persona.h"
#include "inventario.h"

#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

class Bibliotecario : public Persona {
public:
    Bibliotecario(string nombre, string apellidos, string dni, string correoElectronico, string contrasena, string nombreUsuario)
        : Persona(nombre, apellidos, dni, correoElectronico, contrasena, nombreUsuario) {}

    void iniciarSesion() override;
    void registrarse() override;
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

#endif