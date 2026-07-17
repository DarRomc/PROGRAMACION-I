/*Una entidad bancaria necesita uadminitrar la atencion de clientes
a. registrar 5 clientes mediante dni y nombre
b. insertar clientes al final de la cola
c. atender clientees al final de la cola
d. mostrar estado de la cola
e. indicar cuantos clientes quedan
ESTO MEDIANTE OPCIONES
1. registrar cliente 
2. atender cliente
3. mostrar cola
4. salir
*/
#include <iostream>
using namespace std;
struct Cliente {
    string dni;
    string nombre;
};
int main(){
    const int MAX_CLIENTES = 5;
    Cliente clientes[MAX_CLIENTES];
    int frente = 0, fin = 0, cantidadClientes = 0;
    char opcion;

    do {
        cout << "\nOpciones disponibles:" << endl;
        cout << "1: Registrar cliente" << endl;
        cout << "2: Atender cliente" << endl;
        cout << "3: Mostrar cola" << endl;
        cout << "4: Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                if (cantidadClientes < MAX_CLIENTES) {
                    cout << "Ingrese el DNI del cliente: ";
                    cin >> clientes[fin].dni;
                    cout << "Ingrese el nombre del cliente: ";
                    cin >> clientes[fin].nombre;
                    fin = (fin + 1) % MAX_CLIENTES; 
                    cantidadClientes++;
                } else {
                    cout << "La cola de clientes esta llena." << endl;
                }
                break;

            case '2':
                if (cantidadClientes > 0) {
                    cout << "Atendiendo al cliente: " << clientes[frente].nombre 
                         << " (DNI: " << clientes[frente].dni << ")" << endl;
                    frente = (frente + 1) % MAX_CLIENTES; 
                    cantidadClientes--;
                } else {
                    cout << "No hay clientes para atender" << endl;
                }
                break;

            case '3':
                if (cantidadClientes > 0) {
                    cout << "Clientes en la cola:" << endl;
                    for (int i = 0; i < cantidadClientes; i++) {
                        int d = (frente + i) % MAX_CLIENTES; 
                        cout << clientes[d].nombre 
                             << " (DNI: " << clientes[d].dni << ")" << endl;
                    }
                } else {
                    cout << "La cola de clientes esta vacia" << endl;
                }
                break;

            case '4':
                cout << "Gracias por usar el sistema" << endl;
                break;

            default:
                cout << "Opcion no valida. Intentelo otra vez" << endl;
        }
    } while (opcion != '4');

    return 0;
}
