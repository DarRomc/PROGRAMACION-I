#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    string apellido;
    int edad;
public:
    void setNombre(string n) {
        nombre = n;
    }
    void setApellido(string a) {
        apellido = a;
    }
    void setEdad(int e) {
        edad = e;
    }
    string getNombre() {
        return nombre;
    }
    string getApellido() {  
        return apellido;
    }
    int getEdad() {
        return edad;
    }
};

int main() {
    Persona persona1;

    cout << "Ingrese el nombre: ";
    string nombre;
    cin >> nombre;
    persona1.setNombre(nombre);

    cout << "Ingrese el apellido: ";
    string apellido;
    cin >> apellido;
    persona1.setApellido(apellido);

    cout << "Ingrese la edad: ";
    int edad;
    cin >> edad;
    persona1.setEdad(edad);

    cout << "\nDatos de la Persona:" << endl;
    cout << "Nombre: " << persona1.getNombre() << endl;
    cout << "Apellido: " << persona1.getApellido() << endl;
    cout << "Edad: " << persona1.getEdad() << endl;

    return 0;
}

/*proyecto de un sistema en c++, identifica un problema o crea la necesidad con diagrama de clases, despues el codigo,
y al final URL git trabajo final.
*/
