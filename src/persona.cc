/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definicón de métodos de la clase Persona
*/

#include "persona.h"

void Persona::iniciarSesion() {
    cout << "=== Inicio de sesión ===" << endl;
    cout << "Introduzca el nombre de usuario: ";
    cin >> nombreUsuario_;
    cout << "Introduzca la contraseña: ";
    cin >> contrasena_;
}

void Persona::registrarse() {
    cout << "=== Registro de usuario ===" << endl;
    cout << "Introduzca su nombre: ";
    cin >> nombre_;
    cout << "Introduzca sus apellidos: ";
    cin >> apellidos_;
    cout << "Introzca nombre de usuario: ";
    cin >> nombreUsuario_;
    cout << "Introduzca su DNI: ";
    cin >> dni_;
    cout << "Introduzca su correo electrónico: ";
    cin >> correoElectronico_;
    cout << "Establesca una contraseña: ";
    cin >> contrasena_;
    cout << "Introduce tu rol (Administrador, Usuario, Bibliotecario): ";
    cin >> rol_;
}


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

void Usuario::MainMenu() {
    int option;
    do {
        std::cout << "\n=== MENÚ PRINCIPAL DE USUARIO ===\n";
        std::cout << "  [1] Pedir préstamo\n";
        std::cout << "  [2] Devolver Préstamos\n";
        std::cout << "  [3] Cerrar sesión\n";
        std::cout << "  Seleccione una opción: ";
        std::cin >> option;
        if (option == 1) {
            std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
            // std::ifstream inventario("lista_inventario.txt");
            // Inventario inventario_obj(inventario);            
            // this->PedirPrestamo(inventario_obj);
        } else if (option == 2) {
            std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
            // std::ifstream inventario("lista_inventario.txt");
            // Inventario inventario_obj(inventario);
        } else if (option == 3) {
            std::cout << "\nCerrarndo sesión...\n";
        } else {
            std::cout << "\nOpción inválida. Intente nuevamente.\n";
        }
    } while (option != 3);
    std::cout << std::endl;
}


void Bibliotecario::iniciarSesion() {
    cout << "=== Inicio de sesión como bibliotecario ===" << endl;
    Persona::iniciarSesion();
}

void Bibliotecario::registrarse() {
    cout << "=== Registro de bibliotecario ===" << endl;
    Persona::registrarse();
}

void Bibliotecario::MainMenu() {
    std::cout << "\n=== MENÚ PRINCIPAL DE BIBLIOTECARIO ===\n";
    int option;
    do {
        std::cout << "  [1] Opción 1\n";
        std::cout << "  [2] Opción 2\n";
        std::cout << "  [3] Opción 3\n";
        std::cout << "  [4] Cerrar sesión\n";
        std::cout << "  Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 2:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 3:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 4:
                std::cout << "\nCerrarndo sesión...\n";
                break;
            default:
                std::cout << "\nOpción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 4);
    std::cout << std::endl;
}


void Administrador::iniciarSesion() { 
    cout << "=== Inicio de sesión como administrador ===" << endl;
    Persona::iniciarSesion();
}

void Administrador::registrarse() {
    cout << "=== Registro de administrador ===" << endl;
    Persona::registrarse();
}

void Administrador::MainMenu() {
    std::cout << "\n=== MENÚ PRINCIPAL DE ADMINISTRADOR ===\n";
    int option;
    do {
        std::cout << "  [1] Opción 1\n";
        std::cout << "  [2] Opción 2\n";
        std::cout << "  [3] Opción 3\n";
        std::cout << "  [4] Cerrar sesión\n";
        std::cout << "  Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 2:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 3:
                std::cout << "\nFunción a implementar por el momento... Vuelva más tarde!\n";
                break;
            case 4:
                std::cout << "\nCerrando sesión...\n";
                break;
            default:
                std::cout << "\nOpción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 4);
    std::cout << std::endl;
}