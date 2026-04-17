/*un programa que determine un tipo de triangulo se debe solicitar sus 3 lados
(equilatero, isosceles o escaleno), si uno de los lados es negativo o cero, el
programa no debe determinar el tipo de triangulo*/

#include <iostream>
using namespace std;
int main() 
{ 
    float lado1, lado2, lado3;

    do
    {
        cout << "Ingrese el primer lado del triangulo: "; cin >> lado1;
        cout << "Ingrese el segundo lado del triangulo: "; cin >> lado2;
        cout << "Ingrese el tercer lado del triangulo: "; cin >> lado3;
 
        if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) 
        {
            cout << "Los lados deben ser positivos y distinto de 0, intentelo de nuevo" << endl;
        }
    }while(lado1 <= 0 || lado2 <= 0 || lado3 <= 0);


    if (lado1 == lado2 && lado2 == lado3) {
        cout << "El triangulo es equilatero." << endl;
    } 
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        cout << "El triangulo es isosceles." << endl;
    } else {
        cout << "El triangulo es escaleno." << endl;
    }
    return 0;
}