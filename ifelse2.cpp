/*Elabora un programa que calcule el descuento, compra>100 descuento 1%
 >200 descuento 2%, >500 descuento 5%*/
#include <iostream>
using namespace std;

int main()
{
    float compra, descuento = 0;

    cout << "Ingrese el monto de la compra: "; cin >> compra;

    if (compra > 500) {
        descuento = 0.05;
    } else if (compra > 200) {
        descuento = 0.02;
    } else if (compra > 100) {
        descuento = 0.01;
    }

    float montoDescuento = compra * descuento;
    float totalPagar = compra - montoDescuento;

    cout << "Monto de la compra: $" << compra << endl;
    cout << "Descuento aplicado: $" << montoDescuento << endl;
    cout << "Total a pagar: $" << totalPagar << endl;

    return 0;
}