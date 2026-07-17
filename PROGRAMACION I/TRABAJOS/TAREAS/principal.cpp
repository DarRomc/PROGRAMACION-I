#include <iostream>
#include <string>
#include "Curso.cpp"

using namespace std;

void opciones_menu()
{
    cout << "============================" << endl;
    cout << "======Sistema Academico=====" << endl;
    cout << "1. Registrar curso" << endl;
    cout << "2. Registrar docente" << endl;
    cout << "3. Registrar alumno" << endl;
    cout << "4. Mostrar alumnos" << endl;
    cout << "5. Eliminar alumno" << endl;
    cout << "6. Mostrar curso" << endl;
    cout << "7. Salir" << endl;
    cout << "============================" << endl;
}

int main()
{
    int opciones;
    Curso curso;
    
    curso.cargar_alumnos();

    do
    {
        opciones_menu();
        while (!(cin >> opciones)) {
            cout << "Seleccione un numero valido: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (opciones)
        {
        case 1:
            curso.registrar_curso();
            break;
        case 2:
            curso.agregar_docente();
            break;
        case 3:
            curso.agregar_alumno();
            break;
        case 4:
            curso.listar_alumnos();
            break;
        case 5:
            curso.eliminar_alumno();
            break;
        case 6:
            curso.imprimir();
            break;
        case 7:
            cout << "Saliendo y guardando..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opciones != 7);

    return 0;
}
