#include "Usuario.h"

#include <iostream>

using namespace std;

Usuario::Usuario()
    : Persona()
{

}

Usuario::Usuario(string nombre,
                 string usuario,
                 string contrasena)

    : Persona(nombre, usuario, contrasena)
{

}

void Usuario::mostrarMenu()
{

    cout << "\n==============================" << endl;
    cout << "      MENU DEL USUARIO" << endl;
    cout << "==============================" << endl;

    cout << "1. Mostrar Inventario" << endl;
    cout << "2. Buscar Pieza" << endl;
    cout << "3. Cerrar Sesion" << endl;

}

//poliformismo
