//CORAZON DEL SISTEMA

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>

#include "Pieza.h"

using namespace std;

class Inventario
{
private:

    vector<Pieza> piezas;

    string archivoDatos;

public:

    //=========================
    // Constructores
    //=========================

    Inventario();

    Inventario(string archivo);

    //=========================
    // Gestión del archivo
    //=========================

    void cargarArchivo();

    void guardarArchivo();

    //=========================
    // Gestión del inventario
    //=========================

    void registrarPieza(const Pieza& pieza);

    void mostrarInventario() const;

    int buscarPieza(const string& codigo) const;

    void modificarPieza(const string& codigo);

    void eliminarPieza(const string& codigo);

    //=========================
    // Reportes
    //=========================

    void mostrarStockBajo(int minimo = 5) const;

    void mostrarValorInventario() const;

    //=========================
    // Utilidades
    //=========================

    bool existeCodigo(const string& codigo) const;

    bool inventarioVacio() const;

};

#endif
