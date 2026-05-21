/*Elabora un programa que valide la contraseña*/

#include <iostream>
#include <string>
using namespace std;    

int main()
{
    string contrasena, contrasenaCorrecta = "12345";

    do
    {
        cout << "Ingrese la contraseña: "; cin >> contrasena;

        if (contrasena != contrasenaCorrecta) {
            cout << "Contraseña incorrecta. Intente de nuevo." << endl;
        }
    } while (contrasena != contrasenaCorrecta);

    cout << "Contraseña correcta. Bienvenido!" << endl;

    return 0;
}