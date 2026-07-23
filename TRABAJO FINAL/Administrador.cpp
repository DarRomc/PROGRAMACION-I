#include "Administrador.h"

#include <iostream>

using namespace std;

Administrador::Administrador()
    : Persona()
{

}

Administrador::Administrador(string nombre,
                             string usuario,
                             string contrasena)

    : Persona(nombre, usuario, contrasena)
{

}

void Administrador::mostrarMenu()
{

    cout << "\n===================================" << endl;
    cout << "      MENU ADMINISTRADOR" << endl;
    cout << "===================================" << endl;

    cout << "1. Registrar Pieza" << endl;
    cout << "2. Mostrar Inventario" << endl;
    cout << "3. Buscar Pieza" << endl;
    cout << "4. Modificar Pieza" << endl;
    cout << "5. Eliminar Pieza" << endl;
    cout << "6. Reportes" << endl;
    cout << "7. Cerrar Sesion" << endl;

}
