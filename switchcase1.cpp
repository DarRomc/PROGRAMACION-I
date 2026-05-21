/*Elabora un progrma con switch case que calcule la tarifa de acuerdo al tipo
de cliente. Normal: 0%, Vip: 20%, Premium: 30%*/

#include <iostream>
using namespace std;    

int main()
{  
    int tipoCliente;
    float compra, descuento = 0;

    cout << "Ingrese el monto de la compra: "; cin >> compra;
    do{
    cout << "Seleccione el tipo de cliente (1-Normal, 2-VIP, 3-Premium): "; cin >> tipoCliente;
    }while (tipoCliente < 1 || tipoCliente > 3);

    switch (tipoCliente) {
        case 1:
            descuento = 0.0;
            break;
        case 2:
            descuento = 0.20;
            break;
        case 3:
            descuento = 0.30;
            break;
    }

    float montoDescuento = compra * descuento;
    float totalPagar = compra - montoDescuento;

    cout << "Monto de la compra es: " << compra << endl;
    cout << "Descuento aplicado es: " << montoDescuento << endl;
    cout << "Total a pagar es: " << totalPagar << endl;

    return 0;
}