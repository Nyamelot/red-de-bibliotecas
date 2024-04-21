/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de los metodos de la clase Usuario
*/

// #include "usuario.h"

// void Usuario::iniciarSesion() {
//     cout << "=== Inicio de sesión como usuario ===" << endl;
//     Persona::iniciarSesion();
// }

// void Usuario::registrarse() {
//     cout << "=== Registro de usuario ===" << endl;
//     Persona::registrarse();
// }

// Libro Usuario::PedirPrestamo(Inventario& inventario) {
//     cout << "=== Pedir préstamo === " << endl;
//     cout << "Introduzca el libro que desea" << endl;

//     string nombreLibro, nombreAutor;
//     cin >> nombreLibro;
    
//     cout << "Introduzca el autor del libro que desea" << endl;
//     cin >> nombreAutor;

//     if (ConsultarDisponibilidad(nombreLibro,inventario)) {
//         cout << "Libro disponible" << endl;
//         Libro libro(nombreLibro, nombreAutor);
//         return libro;
//     } else {
//         cout << "El libro no se encuentra disponible" << endl;
//         exit(EXIT_FAILURE);
//     }
// }

// //Devolver prestamo 
// void Usuario::DevolverPrestamo(Libro* libro, Inventario& inventario) {
//     cout << "=== Devolver préstamo ===" << endl;
//     cout << "Introduzca el libro que desea devolver" << endl;

//     string nombreLibro, nombreAutor;
//     cin >> nombreLibro;
    
//     cout << "Introduzca el autor del libro que desea devolver" << endl;
//     cin >> nombreAutor;

//     inventario.AgregarLibro(libro);

//     std::cout << "Libro devuelto con éxito" << std::endl;

// }

// void Usuario::MainMenu() {
//     int option;
//     do {
//         std::cout << "\n=== MENÚ PRINCIPAL DE USUARIO ===\n";
//         std::cout << "  [1] Pedir préstamo\n";
//         std::cout << "  [2] Devolver Préstamos\n";
//         std::cout << "  [3] Cerrar sesión\n";
//         std::cout << "  Seleccione una opción: ";
//         std::cin >> option;
//         if (option == 1) {
//             std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
//             // std::ifstream inventario("lista_inventario.txt");
//             // Inventario inventario_obj(inventario);            
//             // this->PedirPrestamo(inventario_obj);
//         } else if (option == 2) {
//             std::cout << "\nFunción en desarrollo... Vuelva más tarde!\n";
//             // std::ifstream inventario("lista_inventario.txt");
//             // Inventario inventario_obj(inventario);
//         } else if (option == 3) {
//             std::cout << "\nCerrarndo sesión...\n";
//         } else {
//             std::cout << "\nOpción inválida. Intente nuevamente.\n";
//         }
//     } while (option != 3);
//     std::cout << std::endl;
// }