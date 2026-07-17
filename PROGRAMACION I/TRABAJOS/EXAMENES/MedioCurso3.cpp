/*Un numero es considerado especial si la suma de sus digitos puede
calcularse hasta obtener un digito, ejemplo:
987: 9+8+7=24 -> 24: 2+4=6
solicite ingresar un numero por teclado
desarrolle una funcion recursiva
debe obtener el resultado esperado-> un digito
*/
#include <iostream>
using namespace std;
int sumaDigitos(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        int suma = 0;
        while (numero > 0) {
            suma = suma + numero % 10; 
            numero /= 10;
        }
        return sumaDigitos(suma);
    }
}
int main() {
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    int resultado = sumaDigitos(numero);

    cout << "El resultado de los digitos es: " << resultado << endl;
    return 0;
}
