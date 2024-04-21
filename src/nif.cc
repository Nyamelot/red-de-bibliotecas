/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @author Diego Hernández Chico
 * @date 16 Mar 2024
 * CORREO: alu0101572062@ull.edu.es
 * @brief Fichero con la definición de los métodos de la clase de Nif
*/



#include "nif.h"

/**
 * @brief Constructor por defecto de un objeto Nif
*/
Nif::Nif() {
  srand(time(NULL));
  valor_nif_ = rand();
  while(valor_nif_ % 100000000 != valor_nif_) {
    valor_nif_ /= 10;
  }
}

/**
 * @brief Constructor por de un objeto Nif para cuando se le pasa un valor. Este constructor ajustará el número de cifras a 8
 * 
 * @param Valor del Nif
*/
Nif::Nif(long valor_nif) {
  while (valor_nif / 10000000 == 0) {
    valor_nif *= 10;
  }
  while(valor_nif % 100000000 != valor_nif) {
    valor_nif /= 10;
  }
  valor_nif_ = valor_nif;
}

/**
 * @brief Sobrecarga del operador módulo para un Nif
 * 
 * @param entero con el que se desea realizar la sobrecarga
*/
int Nif::operator%(int divisor) const {
  return this->valor_nif_ % divisor;
}

/**
 * @brief Sobrecarga del operador de asignación. Como caso especial, se podrá poner el nif a cero para indicar que no tiene número identificador
 * 
 * @param Valor del nif
*/
void Nif::operator=(int valor_nif) {
  if (valor_nif != 0) {
    while (valor_nif / 10000000 == 0) {
      valor_nif *= 10;
    }
    while(valor_nif % 100000000 != valor_nif) {
      valor_nif /= 10;
    } 
  }
  valor_nif_ = valor_nif;
}