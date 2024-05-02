/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 29 Abr 2024
 * @brief Programa para dar soporte a una red de bibliotecas
*/
#include "red_bibliotecas.h"


//Constructor clase red bibliotecas
RedBibliotecas::RedBibliotecas(std::ifstream& archivo_bibliotecas) {
  
  std::string linea;
  std::string nombre, direccion, telefono, horario;

  //Si se abre el fichero
  if (AbrirListado(archivo_bibliotecas,"data/lista_bibliotecas.txt")) {

    //Leemos el fichero por lineas
    while (std::getline(archivo_bibliotecas,linea)) {

      //Creamos un stream de cada linea
      std::stringstream stream(linea); 
      
      //Guardamos el nombre de la bilbioteca
      std::getline(stream,nombre,'|');
      
      //Guardamos la dirección
      std::getline(stream,direccion, '|');
      
      //Guardamos el número de teléfono
      std::getline(stream,telefono, '|');
      
      //Guardamos el horario
      std::getline(stream,horario);
      
      Biblioteca* biblioteca = new Biblioteca(nombre,direccion,telefono,horario);
      bibliotecas_.push_back(biblioteca);
    } 
  } else {
    std::cout << "Error al abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }

  CerarListado(archivo_bibliotecas);
}

//Funcion estatica que comprueba la apartura del fichero con el bibliotecas
bool RedBibliotecas::AbrirListado(std::ifstream& fichero_bibliotecas, std::string nombre_fichero) {

  bool apertura_correcta{true};
  fichero_bibliotecas.open(nombre_fichero);
  if (!fichero_bibliotecas.is_open()) {
    apertura_correcta = false;
  }
  
  return apertura_correcta;
}

//Funcion estatica que comprueba el cerrado del fichero con el bibliotecas
bool RedBibliotecas::CerarListado(std::ifstream& fichero_bibliotecas) {
  bool cerrado_correcto{true};
  fichero_bibliotecas.close();
  if (fichero_bibliotecas.is_open()) {
    cerrado_correcto = false;
  }

  return cerrado_correcto;
}

void RedBibliotecas::MostrarRed() {
  for (int i = 0; i < bibliotecas_.size(); i++) {
    std::cout << "Biblioteca:  " << bibliotecas_[i]->GetNombre() << std::endl;
    std::cout << "  Dirección: " << bibliotecas_[i]->GetDireccion() << std::endl;
    std::cout << "  Teléfono:  " << bibliotecas_[i]->GetTelefono() << std::endl;
    std::cout << "  Horario:   " << bibliotecas_[i]->GetHorario() << std::endl;
    std::cout << std::endl;
  }
}

Biblioteca* RedBibliotecas::BuscarBiblioteca(std::string nombre_biblioteca) {
  Biblioteca* biblioteca_encontrada = nullptr;
  for (int i = 0; i < bibliotecas_.size(); i++) {
    if (bibliotecas_[i]->GetNombre() == nombre_biblioteca) {
      biblioteca_encontrada = bibliotecas_[i];
    }
  }
  return biblioteca_encontrada;
}

std::vector<Biblioteca*> RedBibliotecas::AgregarBiblioteca(Biblioteca* biblioteca) {
  if (BuscarBiblioteca(biblioteca->GetNombre()) != nullptr) return bibliotecas_;
  std::ofstream archivo_salida("data/lista_bibliotecas.txt", std::ios::app);
  if (archivo_salida.is_open()) {
    archivo_salida << "\n" << biblioteca->GetNombre() << "|" << biblioteca->GetDireccion() << "|" << biblioteca->GetTelefono() << "|" << biblioteca->GetHorario();
    archivo_salida.close();
  } else {
    std::cout << "Error al abrir el archivo de salida" << std::endl;
    exit(EXIT_FAILURE);
  }
  bibliotecas_.push_back(biblioteca);
  return bibliotecas_;
}

void RedBibliotecas::EliminarBiblioteca(std::string nombre_biblioteca) {
  std::ifstream archivo_temp("data/lista_bibliotecas.txt");
  std::ofstream archivo_salida("temp.txt");
  std::string linea_temp;
  if (archivo_temp.is_open() && archivo_salida.is_open()) {
    while (std::getline(archivo_temp, linea_temp)) {
      std::stringstream stream(linea_temp);
      std::string nombre_biblioteca_temp;
      std::getline(stream, nombre_biblioteca_temp, '|');
      if (nombre_biblioteca_temp != nombre_biblioteca) {
        archivo_salida << linea_temp << std::endl;
      }
    }
    archivo_temp.close();
    archivo_salida.close();
    std::rename("temp.txt", "data/lista_bibliotecas.txt");
  } else {
    std::cout << "Error al abrir los archivos" << std::endl;
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < bibliotecas_.size(); i++) {
    if (bibliotecas_[i]->GetNombre() == nombre_biblioteca) {
      bibliotecas_.erase(bibliotecas_.begin() + i);
    }
  }
}