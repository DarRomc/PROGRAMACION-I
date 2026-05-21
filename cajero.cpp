#include <iostream>
#include <string>

using namespace std;

int main()
{
    int opcion;
    double retiro, deposito;
    double saldo = 2500.00;
    
    int contrasena_actual = 2026;
    int contrasena_ingresada;
    bool autenticado = false;

    cout << "Bienvenido al Sistema de Cajero Automatico" << endl;

    while (!autenticado) {
        cout << "Ingrese su contrasena para acceder: ";
        cin >> contrasena_ingresada;
        
        if (contrasena_ingresada == contrasena_actual) {
            autenticado = true;
            cout << "Acceso concedido.\n" << endl;
        } else {
            cout << "Contrasena incorrecta. Intente de nuevo.\n" << endl;
        }
    }

    do
    {
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Realizar retiro" << endl;
        cout << "3. Realizar deposito" << endl;
        cout << "4. Cambio de contrasena" << endl;
        cout << "5. Autenticarse nuevamente" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: "; 
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Su saldo actual es: $" << saldo << endl;
                break;
                
            case 2:
                cout << "Ingrese la cantidad a retirar: $"; 
                cin >> retiro;
                
                if (retiro <= 0) {
                    cout << "Error: La cantidad debe ser mayor a 0." << endl;
                } else if (retiro <= saldo) {
                    saldo -= retiro;
                    cout << "Retiro exitoso. Su nuevo saldo es: $" << saldo << endl;
                } else {
                    cout << "Error: Fondos insuficientes." << endl;
                }
                break;
                
            case 3:
                cout << "Ingrese la cantidad a depositar: $"; 
                cin >> deposito;
                
                if (deposito > 0) {
                    saldo += deposito;
                    cout << "Deposito exitoso. Su nuevo saldo es: $" << saldo << endl;
                } else {
                    cout << "Error: La cantidad a depositar debe ser mayor a 0." << endl;
                }
                break;
                
            case 4:
            {
                int pass_actual, pass_nueva, pass_confirmar;
                
                cout << "Ingrese su contrasena ACTUAL: ";
                cin >> pass_actual;
                
                if (pass_actual == contrasena_actual) {
                    cout << "Ingrese su NUEVA contrasena (solo numeros): ";
                    cin >> pass_nueva;
                    cout << "Confirme su NUEVA contrasena: ";
                    cin >> pass_confirmar;
                    
                    if (pass_nueva == pass_confirmar) {
                        contrasena_actual = pass_nueva;
                        cout << "Exito: La contrasena se ha actualizado correctamente." << endl;
                    } else {
                        cout << "Error: Las contrasenas no coinciden. Cancelando operacion." << endl;
                    }
                } else {
                    cout << "Error: Contrasena actual incorrecta. Acceso denegado." << endl;
                }
                break;
            }
                
            case 5:
                autenticado = false;
                cout << "\nCerrando sesion actual..." << endl;
                
                while (!autenticado) {
                    cout << "Por favor, autentiquese nuevamente: ";
                    cin >> contrasena_ingresada;
                    
                    if (contrasena_ingresada == contrasena_actual) {
                        autenticado = true;
                        cout << "Re-autenticacion exitosa." << endl;
                    } else {
                        cout << "Contrasena incorrecta. Intente de nuevo.\n" << endl;
                    }
                }
                break;
                
            case 6:
                cout << "Gracias por usar nuestro cajero automatico. ¡Hasta pronto!" << endl;
                break;
                
            default:
                cout << "Opcion invalida. Por favor, seleccione un numero del 1 al 6." << endl;
        }
    } while(opcion != 6);

    return 0;
}
//holaa xdd
