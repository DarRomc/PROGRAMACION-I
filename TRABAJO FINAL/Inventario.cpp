#include "Inventario.h"
#include "Logger.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

//=========================================================
// Constructores
//=========================================================

Inventario::Inventario()
{
    archivoDatos = "piezas.txt";
    cargarArchivo();
}

Inventario::Inventario(string archivo)
{
    archivoDatos = archivo;
    cargarArchivo();
}

//=========================================================
// Cargar datos desde el archivo
//=========================================================

void Inventario::cargarArchivo()
{
    piezas.clear();

    ifstream archivo(archivoDatos);

    if (!archivo.is_open())
    {
        Logger::registrar("No se encontró el archivo de inventario. Se creará automáticamente.");
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        if(linea.empty())
            continue;

        stringstream ss(linea);

        string codigo;
        string nombre;
        string categoria;
        string marca;
        string precioTexto;
        string stockTexto;

        getline(ss, codigo, ';');
        getline(ss, nombre, ';');
        getline(ss, categoria, ';');
        getline(ss, marca, ';');
        getline(ss, precioTexto, ';');
        getline(ss, stockTexto);

        double precio = stod(precioTexto);
        int stock = stoi(stockTexto);

        Pieza pieza(codigo,
                    nombre,
                    categoria,
                    marca,
                    precio,
                    stock);

        piezas.push_back(pieza);
    }

    archivo.close();
}

//=========================================================
// Guardar datos en archivo
//=========================================================

void Inventario::guardarArchivo()
{
    ofstream archivo(archivoDatos);

    if (!archivo.is_open())
    {
        Logger::registrar("No fue posible guardar el archivo del inventario.");
        return;
    }

    for(const Pieza &pieza : piezas)
    {
        archivo
            << pieza.getCodigo() << ";"
            << pieza.getNombre() << ";"
            << pieza.getCategoria() << ";"
            << pieza.getMarca() << ";"
            << pieza.getPrecio() << ";"
            << pieza.getStock()
            << endl;
    }

    archivo.close();
}

//=========================================================
// Mostrar Inventario
//=========================================================

void Inventario::mostrarInventario() const
{
    if(inventarioVacio())
    {
        cout << "\nNo existen piezas registradas.\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << "                 INVENTARIO DE REPUESTOS\n";
    cout << "===============================================================\n\n";

    cout << left
         << setw(10) << "Codigo"
         << setw(25) << "Nombre"
         << setw(20) << "Categoria"
         << setw(18) << "Marca"
         << setw(10) << "Precio"
         << setw(8) << "Stock"
         << endl;

    cout << string(91,'-') << endl;

    for(const Pieza &pieza : piezas)
    {
        pieza.mostrarInformacion();
    }

    cout << endl;
}

//=========================================================
// Buscar pieza
//=========================================================

int Inventario::buscarPieza(const string& codigo) const
{
    for(size_t i=0; i<piezas.size(); i++)
    {
        if(piezas[i].getCodigo() == codigo)
        {
            return i;
        }
    }

    return -1;
}

//=========================================================
// Verificar si el inventario está vacío
//=========================================================

bool Inventario::inventarioVacio() const
{
    return piezas.empty();
}
//=========================================================
// Verificar si un código ya existe
//=========================================================

bool Inventario::existeCodigo(const string& codigo) const
{
    return buscarPieza(codigo) != -1;
}

//=========================================================
// Registrar una nueva pieza
//=========================================================

void Inventario::registrarPieza(const Pieza& pieza)
{
    try
    {
        // Validar código vacío
        if (pieza.getCodigo().empty())
        {
            throw invalid_argument("El código de la pieza no puede estar vacío.");
        }

        // Validar nombre vacío
        if (pieza.getNombre().empty())
        {
            throw invalid_argument("El nombre de la pieza no puede estar vacío.");
        }

        // Validar código duplicado
        if (existeCodigo(pieza.getCodigo()))
        {
            throw invalid_argument("El código ya se encuentra registrado.");
        }

        // Validar precio
        if (pieza.getPrecio() < 0)
        {
            throw invalid_argument("El precio no puede ser negativo.");
        }

        // Validar stock
        if (pieza.getStock() < 0)
        {
            throw invalid_argument("El stock no puede ser negativo.");
        }

        // Registrar pieza
        piezas.push_back(pieza);

        // Guardar automáticamente
        guardarArchivo();

        cout << "\n===================================";
        cout << "\nPieza registrada correctamente.";
        cout << "\n===================================\n";
    }

    catch(const exception& e)
    {
        Logger::registrar(e.what());

        cout << "\nError: "
             << e.what()
             << endl;
    }
}
//=========================================================
// Modificar una pieza
//=========================================================

void Inventario::modificarPieza(const string& codigo)
{
    try
    {
        int posicion = buscarPieza(codigo);

        if(posicion == -1)
        {
            throw invalid_argument("La pieza no existe.");
        }

        string nombre;
        string categoria;
        string marca;
        double precio;
        int stock;

        cout << "\nNuevo nombre: ";
        getline(cin >> ws, nombre);

        cout << "Nueva categoria: ";
        getline(cin, categoria);

        cout << "Nueva marca: ";
        getline(cin, marca);

        cout << "Nuevo precio: ";
        cin >> precio;

        cout << "Nuevo stock: ";
        cin >> stock;

        if(precio < 0)
            throw invalid_argument("El precio no puede ser negativo.");

        if(stock < 0)
            throw invalid_argument("El stock no puede ser negativo.");

        piezas[posicion].setNombre(nombre);
        piezas[posicion].setCategoria(categoria);
        piezas[posicion].setMarca(marca);
        piezas[posicion].setPrecio(precio);
        piezas[posicion].setStock(stock);

        guardarArchivo();

        cout << "\nPieza modificada correctamente.\n";
    }

    catch(const exception& e)
    {
        Logger::registrar(e.what());

        cout << "\nError: "
             << e.what()
             << endl;
    }
}

//=========================================================
// Eliminar una pieza
//=========================================================

void Inventario::eliminarPieza(const string& codigo)
{
    try
    {
        int posicion = buscarPieza(codigo);

        if(posicion == -1)
        {
            throw invalid_argument("La pieza no existe.");
        }

        piezas.erase(piezas.begin() + posicion);

        guardarArchivo();

        cout << "\nPieza eliminada correctamente.\n";
    }

    catch(const exception& e)
    {
        Logger::registrar(e.what());

        cout << "\nError: "
             << e.what()
             << endl;
    }
}

//=========================================================
// Reporte de stock bajo
//=========================================================

void Inventario::mostrarStockBajo(int minimo) const
{
    if(inventarioVacio())
    {
        cout << "\nInventario vacío.\n";
        return;
    }

    cout << "\n==============================================\n";
    cout << "        PRODUCTOS CON STOCK BAJO\n";
    cout << "==============================================\n\n";

    bool encontrado = false;

    for(const Pieza &pieza : piezas)
    {
        if(pieza.getStock() <= minimo)
        {
            pieza.mostrarInformacion();
            encontrado = true;
        }
    }

    if(!encontrado)
    {
        cout << "No existen productos con stock bajo.\n";
    }
}

//=========================================================
// Valor total del inventario
//=========================================================

void Inventario::mostrarValorInventario() const
{
    double total = 0;

    for(const Pieza &pieza : piezas)
    {
        total += pieza.getPrecio() * pieza.getStock();
    }

    cout << "\n======================================\n";
    cout << " VALOR TOTAL DEL INVENTARIO\n";
    cout << "======================================\n";

    cout << fixed << setprecision(2);

    cout << "\nS/. "
         << total
         << endl;
}
