#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream archivo("datos.txt");
    string linea;
    try {
        // Comprueba si el archivo pudo ser encontrado y abierto
        if (!archivo)
            throw "No se pudo abrir el archivo.";
        cout << "Contenido del archivo:" << endl;
        // Lee el archivo línea por línea
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
    catch (const char *mensaje) {
        cout << "Error: " << mensaje << endl;
    }
}
