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

                if(!autenticacion.iniciarSesion(usuarioLogin, contrasena, esAdministrador))
                {
                    break;
                }

                //--------------------------------------------------
                // Menú Administrador / Usuario
                //--------------------------------------------------
                if(esAdministrador)
                {
                    do
                    {
                        administrador.mostrarMenu();
                        cout << "\nSeleccione una opcion (0 para salir): ";
                        cin >> opcionMenu;

                        switch(opcionMenu)
                        {
                            case 1: // Registrar pieza
                                cout << "\nCodigo: ";
                                cin >> codigo;
                                cin.ignore();
                                cout << "Nombre: ";
                                getline(cin, nombre);
                                cout << "Categoria: ";
                                getline(cin, categoria);
                                cout << "Marca: ";
                                getline(cin, marca);
                                cout << "Precio: ";
                                cin >> precio;
                                cout << "Stock: ";
                                cin >> stock;

                                inventario.registrarPieza(Pieza(codigo, nombre, categoria, marca, precio, stock));
                                break;

                            case 2: // Mostrar inventario específico
                                cout << "\nCodigo de la pieza: ";
                                cin >> codigo;

                                if(inventario.buscarPieza(codigo) == -1) {
                                    cout << "\nLa pieza no existe.\n";
                                } else {
                                    cout << "\nLa pieza fue encontrada.\n";
                                    inventario.mostrarInventario();
                                }
                                break;

                            case 3: // Buscar pieza
                                cout << "\nCodigo de la pieza: ";
                                cin >> codigo;

                                if(inventario.buscarPieza(codigo) == -1) {
                                    cout << "\nLa pieza no existe.\n";
                                } else {
                                    cout << "\nLa pieza fue encontrada.\n";
                                    inventario.mostrarInventario(); 
                                }
                                break;

                            case 4: // Modificar pieza
                                cout << "\nCodigo de la pieza a modificar: ";
                                cin >> codigo;
                                inventario.modificarPieza(codigo);
                                break;

                            case 5: // Eliminar pieza
                                cout << "\nCodigo de la pieza a eliminar: ";
                                cin >> codigo;
                                inventario.eliminarPieza(codigo);
                                break;

                            case 6: // Reportes
                            {
                                int opcionReporte;
                                do
                                {
                                    cout << "\n=========================================\n";
                                    cout << " REPORTES DEL INVENTARIO\n";
                                    cout << "=========================================\n";
                                    cout << "1. Productos con stock bajo\n";
                                    cout << "2. Valor total del inventario\n";
                                    cout << "0. Regresar\n";
                                    cout << "\nSeleccione una opcion: ";
                                    cin >> opcionReporte;

                                    switch(opcionReporte)
                                    {
                                        case 1:
                                            inventario.mostrarStockBajo(5);
                                            break;
                                        case 2:
                                            inventario.mostrarValorInventario();
                                            break;
                                        case 0:
                                            break;
                                        default:
                                            cout << "\nOpcion invalida.\n";
                                    }
                                } while(opcionReporte != 0); // Faltaba el cierre del while de reportes
                                break;
                            } // Fin case 6

                            case 0:
                                cout << "\nCerrando sesion de administrador...\n";
                                break;

                            default:
                                cout << "\nOpcion invalida.\n";
                                break;
                        }
                    } while(opcionMenu != 0); 
                }
                else
                {
                    // Lógica para usuario normal
                    cout << "\nBienvenido al panel de Usuario.\n";
                    // Aquí iría el menú del usuario normal (empleado)
                }
                break; // Fin case 1 principal

            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
                break;
        }
    } while(opcionPrincipal != 0); 

    return 0;
}
