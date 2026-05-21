#include <iostream>
using namespace std;

int main()
{
    int a, x, y;
    do
    {
        cout<<"CALCULADORA"<<endl;
        cout<<"Ingrese el primer numero: "; cin>>x;
        cout<<"Ingrese el segundo numero: "; cin>>y;
        do
        {
            cout<<"1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir\n"; cin>>a;
        } while (a<=0 || a>5);
        switch (a)
        {
            case 1:
                cout<<"El resultado de la suma es: "<<x+y<<endl;
                break;
            case 2:
                cout<<"El resultado de la resta es: "<<x-y<<endl;
                break;
            case 3:
                cout<<"El resultado de la multiplicacion es: "<<x*y<<endl;
                break;
            case 4:
                cout<<"El resultado de la division es: "<<x/y<<endl;
                break;
        }
        cout<<"Desea realizar otra operacion? (Ingrese 5 para salir): "; cin>>a;
    }while(a!=5);
    
    return 0;
}