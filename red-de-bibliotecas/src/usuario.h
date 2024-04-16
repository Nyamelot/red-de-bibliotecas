
#pragma once
#include <iostream>

#include "persona.h"

class Usuario : public Persona {
 public:
    Usuario(string _nombre, string _apellidos, string _dni, string _correoElectronico)
        : Persona(_nombre, _apellidos, _dni, _correoElectronico) {}

    void recogerinformacion() override {
        //Aqui pondriamos la informacion diferente que se debe recoger del usuario 
    }

    // Método para mostrar información específica de Usuario si es necesario
    void mostrarInformacion() override {
        cout << "=== Información del Usuario ===" << endl;
        Persona::mostrarInformacion();

        //Aqui podemos añadir mas informacion sobre el usuario 
    }

};