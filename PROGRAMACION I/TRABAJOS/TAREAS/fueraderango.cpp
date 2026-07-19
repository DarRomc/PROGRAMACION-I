#include <iostream>
using namespace std;

class Estudiante {
private:
    // Guarda la nota o promedio del estudiante
    float promedio;
public:
    void ingresarNota(float nota) {
        // Comprueba que la nota ingresada esté dentro del rango permitido
        if (nota < 0 || nota > 20)
            throw "La nota ingresada esta fuera del rango permitido.";

        // Si la nota es correcta, se almacena en el atributo promedio
        promedio = nota;

        cout << "Promedio registrado: " << promedio << endl;
    }
};
int main() {
    Estudiante e;
    float nota;
    cout << "Ingrese el promedio del estudiante: ";
    cin >> nota;
    try {

        // Se intenta registrar la nota del estudiante
        e.ingresarNota(nota);
    }
    catch (const char *mensaje) {
        // Si ocurre un error, se captura la excepción y se informa al usuario
        cout << "Error: " << mensaje << endl;
    }
}
