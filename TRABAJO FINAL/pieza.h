#ifndef PIEZA_H
#define PIEZA_H

#include <string>

using namespace std;

class Pieza
{
private:

    string codigo;
    string nombre;
    string categoria;
    string marca;

    double precio;

    int stock;

public:

    // Constructor por defecto
    Pieza();

    // Constructor con parámetros
    Pieza(string codigo,
          string nombre,
          string categoria,
          string marca,
          double precio,
          int stock);

    // Getters
    string getCodigo() const;
    string getNombre() const;
    string getCategoria() const;
    string getMarca() const;
    double getPrecio() const;
    int getStock() const;

    // Setters
    void setCodigo(string codigo);
    void setNombre(string nombre);
    void setCategoria(string categoria);
    void setMarca(string marca);
    void setPrecio(double precio);
    void setStock(int stock);

    // Mostrar información
    void mostrarInformacion() const;

};

#endif

/*
Encapsulamiento
Sobrecarga de constructores
Validación de datos
*/
