/*Crea un arreglo nota [3] mediante fxcj calcular promedio y nota mayor
int suma (5,3);
void suma()
*/

#include <iostream>

using namespace std;

// 1. Funciones para procesar el arreglo de notas
float calcularPromedio(int notas[], int tamano) {
    int suma = 0;
    for(int i = 0; i < tamano; i++) {
        suma += notas[i];
    }
    return (float)suma / tamano; // Se hace un cast a float para tener decimales
}

int calcularMayor(int notas[], int tamano) {
    int mayor = notas[0]; // Asumimos que la primera es la mayor inicialmente
    for(int i = 1; i < tamano; i++) {
        if(notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    return mayor;
}

// 2. Demostración de las funciones suma solicitadas

// Retorna un valor entero que luego puedes almacenar o imprimir
int sumaConRetorno(int a, int b) {
    return a + b;
}

// No retorna ningún valor, simplemente ejecuta una acción (como imprimir)
void sumaVoid(int a, int b) {
    cout << "La suma calculada dentro del void es: " << (a + b) << endl;
}

int main() {
    // Declaración del arreglo de 3 posiciones
    int nota[3];

    cout << "--- SISTEMA DE NOTAS ---" << endl;
    
    // Bucle para llenar el arreglo
    for(int i = 0; i < 3; i++) {
        cout << "Ingresa la nota " << i + 1 << ": ";
        cin >> nota[i];
    }

    // Llamadas a las funciones pasando el arreglo y su tamaño
    float promedio = calcularPromedio(nota, 3);
    int notaMayor = calcularMayor(nota, 3);

    // Mostrar resultados de las notas
    cout << "\nResultados:" << endl;
    cout << "El promedio es: " << promedio << endl;
    cout << "La nota mayor es: " << notaMayor << endl;

    cout << "\n--- DEMOSTRACIÓN DE INT Y VOID ---" << endl;
    
    // Cómo usar la función int (se captura o imprime su retorno)
    int resultado = sumaConRetorno(5, 3);
    cout << "Resultado de 'int suma(5,3)': " << resultado << endl;

    // Cómo usar la función void (se llama directamente)
    cout << "Resultado de 'void suma(5,3)': ";
    sumaVoid(5, 3);

    return 0;
}
