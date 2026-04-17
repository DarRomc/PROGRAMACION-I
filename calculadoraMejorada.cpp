#include <iostream>
using namespace std;
int a, b, Resultado = 0;

void Suma(){
    Resultado = a+b;
    cout<<"La suma es: "<<Resultado<<endl;
}

void Resta(){
    Resultado = a-b;
    cout<<"La resta es: "<<Resultado<<endl;
}

void Multiplicacion(){
    Resultado = a * b;
    cout<<"La multiplicacion es: "<<Resultado<<endl;
}

void Division(){
    if (b == 0) {
        cout << "Error: No se puede dividir por cero" << endl;
        return;
    }
    Resultado = a / b;
    cout<<"La division es: "<<Resultado<<endl;
}

int main(){
    a=10, b=5;
    Suma();
    Resta();
    Multiplicacion();
    Division();

    return 0;
}