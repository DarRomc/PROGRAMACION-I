#include <iostream>
using namespace std;

int main()
{
    int a;
    do
    {
        cout<<"Ingrese su edad(numero positivo distinto de 0): "; cin>>a;
    } while (a <= 0);

    if (a <= 12)
    {
        cout<<"Eres un niño"<<endl;
    }
    else if (a > 12 && a <= 18)
    {
        cout<<"Eres un Adolescente"<<endl;
    }
    else if (a > 18 && a <= 59)
    {
        cout<<"Eres un Adulto"<<endl;
    }
    else if (a >= 60 && a <= 90) 
    {
        cout<<"Eres un adulto mayor"<<endl;
    }
}