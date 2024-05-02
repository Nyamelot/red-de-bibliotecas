/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @author Diego Hernández Chico
 * @date 16 Mar 2024
 * CORREO: alu0101572062@ull.edu.es
 * @brief Fichero con la declaración de la clase de Nif
*/

// #ifndef NIF_H
// #define NIF_H

// #include <vector>
// #include <ctime>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <iomanip>


// class Nif {
//  public:
//   Nif();
//   Nif(long valor_nif);
//   ~Nif() {  };
//   operator long() const { return valor_nif_; }
//   int operator%(int) const;
//   void operator=(int);
//   private:
//   long valor_nif_;
// };

// #endif

#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>


class Nif {
 private:
  long numero;

 public:
  // Constructor por defecto
  // El numero tiene que ser de 8 digitos
  Nif() {
    numero = rand()  % 90000000 + 10000000;
  }

  // Constructor de cambio de tipo a partir de un dato entero long
  Nif(long num) {
    // Verificar que el número tenga 8 dígitos
    std::string number_str = std::to_string(num);

    while (std::to_string(num).size() != 8 && number_str.front() != '-') {
      std::cerr << "\033[1;31m-> Error: El número debe tener 8 dígitos.\033[0m" << std::endl;
      std::cout << "Introduzca un DNI válido: ";
      std::cin >> num;
    }
    numero = num;
  }

  // Operador de comparación ==
  bool operator==(const Nif& otro) const {
    return numero == otro.numero;
  }

  // Operador de comparación !=
  bool operator!=(const Nif& otro) const {
    return !(*this == otro);
  }

  // Operador de conversión a long
  operator long() const {
    return numero;
  }

  Nif& operator+=(const Nif& other) {
    this->numero += other.numero;
    return *this;
  }
    // Método para leer un objeto Nif desde std::cin
   friend std::istream& operator>>(std::istream& is, Nif& n) {
        is >> n.numero;
        return is;
    }
};