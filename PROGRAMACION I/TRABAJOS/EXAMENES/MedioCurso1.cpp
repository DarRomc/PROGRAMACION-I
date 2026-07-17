/*Una empresa registra ventas diarias de una tienda durante 30 dias
a. permite registrar las ventas
b. calcular el promedio de ventas.
c. contar cuantos dias tuvieron ventas mayores
d. mostrar los resultados obtenidos.
*/

#include <iostream>
using namespace std;

int main() {
    const int dias = 30;
    double ventas[dias];
    
    double sumaVentas = 0.0;
    double promedio = 0.0;
    int diasMayoresAlPromedio = 0;

    cout << "Sistema de Registro de Ventas" << endl;

    for (int i = 0; i < dias; i++) {
        cout << "Ingrese la venta del dia " << (i+1) << ": ";
        cin >> ventas[i];

        sumaVentas = sumaVentas + ventas[i]; 
    }

    promedio = sumaVentas / dias;

    for (int i = 0; i < dias; i++) {
        if (ventas[i] > promedio) {
            diasMayoresAlPromedio++;
        }
    }
    cout << "\nResultados Obtenidos" << endl;
    cout << "Suma total de ventas: " << sumaVentas << endl;
    cout << "Promedio diario de ventas: " << promedio << endl;
    cout << "Dias con ventas mayores al promedio: " << diasMayoresAlPromedio << endl;

    return 0;
}
