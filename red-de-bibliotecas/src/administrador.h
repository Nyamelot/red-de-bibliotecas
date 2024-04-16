
#pragma once
#include <iostream>
#include "persona.h"

class Administrador : public Persona {
 public:
    Administrador(string _nombre, string _apellidos, string _dni, string _correoElectronico)
        : Persona(_nombre, _apellidos, _dni, _correoElectronico) {}

    void recogerinformacion() override {
        // Aquí pondríamos la información diferente que se debe recoger del administrador
    }

    // Método para mostrar información específica de Administrador si es necesario
    void mostrarInformacion() override {
        cout << "=== Información del Administrador ===" << endl;
        Persona::mostrarInformacion();
        // Aquí podemos añadir más información sobre el administrador
    }
};