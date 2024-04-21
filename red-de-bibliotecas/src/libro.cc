/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de los métodos de la clase Libro
*/

#include "libro.h"

void Libro::PonerEnPrestamo(std::string nombre_usuario) {
  nombre_propietario_ = nombre_usuario;
  en_prestamo_ = true;
  dias_para_devolucion_ = 30;

}