#include <iostream>
using namespace std;

int main() {
    int anyo;
    cout << "Ingrese un año: ";
    cin >> anyo;

    if ((anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0))
        cout << anyo << " es bisiesto." << endl;
    else
        cout << anyo << " no es bisiesto." << endl;

    return 0;
}
