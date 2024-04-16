
#pragma once
#include <iostream>
#include "persona.h"

// Clase derivada Bibliotecario
class Bibliotecario : public Persona {
 public:
    Bibliotecario(string _nombre, string _apellidos, string _dni, string _correoElectronico)
        : Persona(_nombre, _apellidos, _dni, _correoElectronico) {}

    void recogerinformacion() override {
        //Aqui pondriamos la informacion diferente que se debe recoger del bibliotecario
    }

    // Método para mostrar información específica de Bibliotecario si es necesario
    void mostrarInformacion() override {
        cout << "=== Información del Bibliotecario ===" << endl;
        Persona::mostrarInformacion();
        //Aqui podemos añadir mas informacion sobre el bibliotecario

    }
};