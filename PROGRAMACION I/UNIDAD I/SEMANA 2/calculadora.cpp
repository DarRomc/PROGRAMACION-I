#include <iostream>
using namespace std;

int main() {
    float n1, n2;

    cout << "Digite los dos numeros: "; cin >> n1 >> n2;

    cout << "La suma es : " << n1 + n2 << endl;
    cout << "La resta es : " << n1 - n2 << endl;
    cout << "La multiplicación es : " << n1 * n2 << endl;

    if (n2 != 0)
        cout << "La división es : " << n1 / n2 << endl;
    else
        cout << "La división no es posible (división por cero)" << endl;

    return 0;
}
