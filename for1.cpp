/*elabora un programa que calcule la sumatoria de numeros
pares e impares del 1 al 100 (1 % 2 es par) (n % 2 es par)*/
#include <iostream>
using namespace std;

int main()
{
    int sumPar = 0, sumImpar = 0;

    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            sumPar += i;
        } else {
            sumImpar =  sumImpar+i;
        }
    }

    cout << "La sumatoria de numeros pares del 1 al 100 es: " << sumPar << endl;
    cout << "La sumatoria de numeros impares del 1 al 100 es: " << sumImpar << endl;

    return 0;
}