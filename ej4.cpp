
#include <iostream>
using namespace std;

int main()
{	
	int a;
	do
	{
		cout<<"Ingrese un dia de la semana 1-7\n"; cin>>a;
		if (a<=0 || a>=8)
		{
			cout<<"Numero no valido, intente de nuevo."<<endl;
		}
	}while(a<=0 || a>=8); 
	
	switch (a)
	{
		case 1:
			cout<<"Lunes, Laborable"<<endl;
			break;
		case 2:
			cout<<"Martes, Laborable"<<endl;
			break;
		case 3:
			cout<<"Miercoles, Laborable"<<endl;
			break;
		case 4:
			cout<<"Jueves, Laborable"<<endl;
			break;
		case 5:
			cout<<"Viernes, Laborable"<<endl;
			break;
		case 6:
			cout<<"Sabado, NO Laborable"<<endl;
			break;
		case 7:
			cout<<"Domingo, NO Laborable"<<endl;
			break;
	}
	return 0;
}
