/**
 * Universidad de La Laguna
 * Escuela Superior de Ingniería y tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Software
 * 
 * @date 15 Abr 2024
 * @brief Fichero con la definición de los métodos de la clase Inventario
*/

#include "inventario.h"

//Constructor clase inventario
Inventario::Inventario(std::ifstream& archivo_inventario) {
  
  std::string linea;
  std::string nombre_libro, nombre_autor, en_prestamo_str, dias_para_devolucion_str;
  int prestamo_int, dias_int;

  //Si se abre el fichero
  if (AbrirInventario(archivo_inventario,"lista_inventario.txt")) {

    //Leemos el fichero por lineas
    while (std::getline(archivo_inventario,linea)) {

      //Creamos un stream de cada linea
      std::stringstream stream(linea); 
      
      //Guardamos el nombre del libro
      std::getline(stream,nombre_libro,'|');
      
      //Guardamos el nombre del autor
      std::getline(stream,nombre_autor, '|');
      
      //Guardamos si esta en prestamo o no, y lo convertimos a entero
      std::getline(stream,en_prestamo_str, '|');
      prestamo_int = std::stoi(en_prestamo_str);
      
      //Guardamos los dias para devolucion y lo convertimos a entero
      std::getline(stream,dias_para_devolucion_str);
      dias_int = std::stoi(dias_para_devolucion_str);
      
      Libro* libro = new Libro(nombre_libro,nombre_autor,prestamo_int,dias_int);
      inventario_.push_back(libro);
    } 
  } else {
    std::cout << "Error al abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }

  CerarInventario(archivo_inventario);
}

//Funcion estatica que comprueba la apartura del fichero con el inventario
bool Inventario::AbrirInventario(std::ifstream& fichero_inventario, std::string nombre_fichero) {

  bool apertura_correcta{true};
  fichero_inventario.open(nombre_fichero);
  if (!fichero_inventario.is_open()) {
    apertura_correcta = false;
  }
  
  return apertura_correcta;
}

//Funcion estatica que comprueba el cerrado del fichero con el inventario
bool Inventario::CerarInventario(std::ifstream& fichero_inventario) {
  bool cerrado_correcto{true};
  fichero_inventario.close();
  if (fichero_inventario.is_open()) {
    cerrado_correcto = false;
  }

  return cerrado_correcto;
}

Libro* Inventario::BuscarLibro(std::string nombre_libro) {
  for (int i = 0; i < inventario_.size(); i++) {
    if (inventario_[i]->GetNombre() == nombre_libro) {
      return inventario_[i];
    }
  }
  return nullptr;
}

//Funcion que agrega un libro al inventario
std::vector<Libro*> Inventario::AgregarLibro(Libro* libro) {
  if (BuscarLibro(libro->GetNombre()) != nullptr) return inventario_;
  std::ofstream archivo_salida("lista_inventario.txt", std::ios::app);
  if (archivo_salida.is_open()) {
    archivo_salida << "\n" << libro->GetNombre() << "|" << libro->GetAutor() << "|" << libro->GetEnPrestamo() << "|" << libro->GetDiasParaDevolucion();
    archivo_salida.close();
  } else {
    std::cout << "Error al abrir el archivo de salida" << std::endl;
    exit(EXIT_FAILURE);
  }
  inventario_.push_back(libro);
  return inventario_;
}

void Inventario::EliminarLibro(std::string nombre_libro) {
  std::ifstream archivo_temp("lista_inventario.txt");
  std::ofstream archivo_salida("temp.txt");
  std::string linea_temp;

  if (archivo_temp.is_open() && archivo_salida.is_open()) {
    while (std::getline(archivo_temp, linea_temp)) {
      std::stringstream stream(linea_temp);
      std::string nombre_libro_temp;
      std::getline(stream, nombre_libro_temp, '|');
      if (nombre_libro_temp != nombre_libro) {
        archivo_salida << linea_temp << std::endl;
      }
    }
    archivo_temp.close();
    archivo_salida.close();
    std::rename("temp.txt", "lista_inventario.txt");
  } else {
    std::cout << "Error al abrir los archivos" << std::endl;
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < inventario_.size(); i++) {
    if (inventario_[i]->GetNombre() == nombre_libro) {
      inventario_.erase(inventario_.begin() + i);
    }
  }
}

//Funcion que muestra el inventario
void Inventario::MostrarInventario() {
  for (int i = 0; i < inventario_.size(); i++) {
    std::cout << "Libro " << i+1 << ": " << inventario_[i]->GetNombre() << " de " << inventario_[i]->GetAutor() << std::endl;
  }
}