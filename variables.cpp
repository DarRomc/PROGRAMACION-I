#include <iostream>
using namespace std;
int contador = 0;

int funcion1(int contador)
{
    return contador = 10;
}

int funcion2(int contador)
{
    return contador = 5;
}

int main ()
{
    int contador = 0;
    contador = funcion2(contador);
    contador = funcion1(contador);
    cout << "El valor de contador es: " << contador << endl;
    return 0;
}
