#include <iostream>
#include <string>

using namespace std;

int main() {
    string contrasena_correcta = "12345";
    string contrasena_ingresada;

    cout << "Sistema de Verificacion" << endl;

    do {
        cout << "Ingrese la contrasena: ";
        cin >> contrasena_ingresada;

        if (contrasena_ingresada == contrasena_correcta) {
            cout << "Acceso concedido" << endl;
        } else {
            cout << "Error: Contrasena incorrecta. Intente nuevamente.\n" << endl;
        }

    } while (contrasena_ingresada != contrasena_correcta);

    return 0;
}