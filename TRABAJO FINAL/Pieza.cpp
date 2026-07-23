#include "Pieza.h"

#include <iostream>
#include <iomanip>

using namespace std;

Pieza::Pieza()
{
    codigo = "";
    nombre = "";
    categoria = "";
    marca = "";
    precio = 0;
    stock = 0;
}

Pieza::Pieza(string codigo,
             string nombre,
             string categoria,
             string marca,
             double precio,
             int stock)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->categoria = categoria;
    this->marca = marca;
    this->precio = precio;
    this->stock = stock;
}

// Getters

string Pieza::getCodigo() const
{
    return codigo;
}

string Pieza::getNombre() const
{
    return nombre;
}

string Pieza::getCategoria() const
{
    return categoria;
}

string Pieza::getMarca() const
{
    return marca;
}

double Pieza::getPrecio() const
{
    return precio;
}

int Pieza::getStock() const
{
    return stock;
}

// Setters

void Pieza::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void Pieza::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Pieza::setCategoria(string categoria)
{
    this->categoria = categoria;
}

void Pieza::setMarca(string marca)
{
    this->marca = marca;
}

void Pieza::setPrecio(double precio)
{
    this->precio = precio;
}

void Pieza::setStock(int stock)
{
    this->stock = stock;
}

void Pieza::mostrarInformacion() const
{
    cout << left
         << setw(10) << codigo
         << setw(25) << nombre
         << setw(20) << categoria
         << setw(18) << marca
         << setw(10) << fixed << setprecision(2) << precio
         << setw(10) << stock
         << endl;
}
