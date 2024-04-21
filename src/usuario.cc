/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de los metodos de la clase Usuario
*/

#include "usuario.h"

void Usuario::iniciarSesion() {
    cout << "=== Inicio de sesión como usuario ===" << endl;
    Persona::iniciarSesion();
}

void Usuario::registrarse() {
    cout << "=== Registro de usuario ===" << endl;
    Persona::registrarse();
}

Libro Usuario::PedirPrestamo(Inventario& inventario) {
    cout << "=== Pedir préstamo === " << endl;
    cout << "Introduzca el libro que desea" << endl;

    string nombreLibro, nombreAutor;
    cin >> nombreLibro;
    
    cout << "Introduzca el autor del libro que desea" << endl;
    cin >> nombreAutor;

    if (ConsultarDisponibilidad(nombreLibro,inventario)) {
        cout << "Libro disponible" << endl;
        Libro libro(nombreLibro, nombreAutor);
        return libro;
    } else {
        cout << "El libro no se encuentra disponible" << endl;
        exit(EXIT_FAILURE);
    }
}

//Devolver prestamo 
void Usuario::DevolverPrestamo(Libro* libro, Inventario& inventario) {
    cout << "=== Devolver préstamo ===" << endl;
    cout << "Introduzca el libro que desea devolver" << endl;

    string nombreLibro, nombreAutor;
    cin >> nombreLibro;
    
    cout << "Introduzca el autor del libro que desea devolver" << endl;
    cin >> nombreAutor;

    inventario.AgregarLibro(libro);

    std::cout << "Libro devuelto con éxito" << std::endl;

}
