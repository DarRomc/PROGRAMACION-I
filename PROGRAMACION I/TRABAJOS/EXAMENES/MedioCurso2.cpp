/*Una universidad almacena notas de 5 estudiantes.
a. permitir registrar las notas (4)
b. calcula el promedio por cada estudiante.
c. identifique al estudiante con mayor promedio.
d. mostrar estudiantes aprobados y desaporbados.
*/
#include <iostream>
#include <string>

using namespace std;

const int NUM_NOTAS = 4;

struct Estudiante {
    string nombre;
    double notas[NUM_NOTAS];
    double promedio;
    bool aprobado;
};

int main() {
    const int NUM_ESTUDIANTES = 5;
    const double NOTA_APROBATORIA = 10.5; 

    Estudiante estudiantes[NUM_ESTUDIANTES]; 
    
    int indiceMayorPromedio = 0;
    double mayorPromedio = 0.0;

    cout << "Sistema de Registro de Notas" << endl;

    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        cout << "\nDatos del Estudiante " << (i + 1) << endl;
        cout << "Nombre (sin espacios): ";
        cin >> estudiantes[i].nombre;

        double sumaNotas = 0.0;

        for (int j = 0; j < NUM_NOTAS; j++) {
            cout << "Ingrese la nota " << (j + 1) << ": ";
            cin >> estudiantes[i].notas[j];
            sumaNotas += estudiantes[i].notas[j];
        }

        estudiantes[i].promedio = sumaNotas / NUM_NOTAS;
        
        estudiantes[i].aprobado = (estudiantes[i].promedio >= NOTA_APROBATORIA);

        if (estudiantes[i].promedio > mayorPromedio) {
            mayorPromedio = estudiantes[i].promedio;
            indiceMayorPromedio = i;
        }
    }

    cout << "\n Resultados y Estado de los Estudiantes" << endl;
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        cout << "Estudiante: " << estudiantes[i].nombre 
             << "\t| Promedio: " << estudiantes[i].promedio 
             << "\t| Estado: " << (estudiantes[i].aprobado ? "Aprobado" : "Desaprobado") << endl;
    }
    cout << "El mayor promedio es de " << estudiantes[indiceMayorPromedio].nombre 
         << " con " << mayorPromedio << " puntos." << endl;

    return 0;
}
