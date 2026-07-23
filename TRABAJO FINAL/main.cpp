#include <iostream>
#include <string>

#include "Administrador.h"
#include "Usuario.h"
#include "Autenticacion.h"
#include "Inventario.h"
#include "Pieza.h"

using namespace std;

int main()
{
    //--------------------------------------------------
    // Objetos principales
    //--------------------------------------------------

    Inventario inventario;
    Autenticacion autenticacion;

    Administrador administrador;
    Usuario usuario;

    //--------------------------------------------------
    // Variables generales
    //--------------------------------------------------

    bool esAdministrador = false;

    int opcionPrincipal = 0;
    int opcionMenu = 0;

    string usuarioLogin;
    string contrasena;

    string codigo;
    string nombre;
    string categoria;
    string marca;

    double precio;
    int stock;

    //--------------------------------------------------
    // Menú principal
    //--------------------------------------------------

    do
    {
        cout << "\n=============================================\n";
        cout << " SISTEMA DE INVENTARIO DE REPUESTOS\n";
        cout << "=============================================\n";

        cout << "1. Iniciar sesion\n";
        cout << "0. Salir\n";

        cout << "\nSeleccione una opcion: ";
        cin >> opcionPrincipal;

        switch(opcionPrincipal)
        {

        //--------------------------------------------------
        // Iniciar sesión
        //--------------------------------------------------

        case 1:

            cout << "\nUsuario: ";
            cin >> usuarioLogin;

            cout << "Contrasena: ";
            cin >> contrasena;

            if(!autenticacion.iniciarSesion(usuarioLogin,
                                            contrasena,
                                            esAdministrador))
            {
                break;
            }

            //--------------------------------------------------
            // Menú Administrador
            //--------------------------------------------------

            if(esAdministrador)
            {
                do
                {
                    administrador.mostrarMenu();

                    cout << "\nSeleccione una opcion: ";
                    cin >> opcionMenu;

                    switch(opcionMenu)
                    {

                    //------------------------------------------
                    // Registrar pieza
                    //------------------------------------------

                    case 1:

                        cout << "\nCodigo: ";
                        cin >> codigo;

                        cin.ignore();

                        cout << "Nombre: ";
                        getline(cin,nombre);

                        cout << "Categoria: ";
                        getline(cin,categoria);

                        cout << "Marca: ";
                        getline(cin,marca);

                        cout << "Precio: ";
                        cin >> precio;

                        cout << "Stock: ";
                        cin >> stock;

                        inventario.registrarPieza(
                            Pieza(
                                codigo,
                                nombre,
                                categoria,
                                marca,
                                precio,
                                stock
                            )
                        );

                        break;

                    //------------------------------------------
                    // Mostrar inventario
                    //------------------------------------------

                    case 2:

                        inventario.mostrarInventario();

                        break;

                    //------------------------------------------
                    // Buscar
                    //------------------------------------------

                    case 3:

                        // Parte 2

                        break;

                    //------------------------------------------
                    // Modificar
                    //------------------------------------------

                    case 4:

                        // Parte 2

                        break;

                    //------------------------------------------
                    // Eliminar
                    //------------------------------------------

                    case 5:

                        // Parte 2

                        break;

                    //------------------------------------------
                    // Reportes
                    //------------------------------------------

                    case 6:

                        // Parte 2

                        break;

                    //------------------------------------------

                    case 0:

                        cout << "\nSesion finalizada.\n";

                        break;

                    default:

                        cout << "\nOpcion invalida.\n";

                    }

                }
                while(opcionMenu != 0);
            }

            //--------------------------------------------------
            // Menú Usuario
            //--------------------------------------------------

            else
            {
                do
                {
                    usuario.mostrarMenu();

                    cout << "\nSeleccione una opcion: ";
                    cin >> opcionMenu;

                    switch(opcionMenu)
                    {

                    case 1:

                        inventario.mostrarInventario();

                        break;

                    case 2:

                        // Parte 2

                        break;

                    case 0:

                        cout << "\nSesion finalizada.\n";

                        break;

                    default:

                        cout << "\nOpcion invalida.\n";

                    }

                }
                while(opcionMenu != 0);
            }

            break;

        //--------------------------------------------------

        case 0:

            cout << "\nGracias por utilizar el sistema.\n";

            break;

        default:

            cout << "\nOpcion invalida.\n";

        }

    }
    while(opcionPrincipal != 0);

    return 0;
}
