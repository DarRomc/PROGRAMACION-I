#include <iostream>
#include <string>
#include <fstream> 
#include "Persona.cpp"

using namespace std;

class Curso
{
private:
    int id;
    string nombre;
    int credito;
    Persona docente;
    Persona estudiantes[5];
    int total_alumnos = 0;

public:
    Curso() {}
    Curso(int _id, string _nombre, int _credito)
    {
        this->id = _id;
        this->nombre = _nombre;
        this->credito = _credito;
    }
    
    int get_id() { return this->id; }
    void set_id(int _id) { this->id = _id; }
    string get_nombre() { return this->nombre; }
    void set_nombre(string _nombre) { this->nombre = _nombre; }
    int get_credito() { return this->credito; }
    void set_credito(int _credito) { this->credito = _credito; }
    
    /*metodos*/
    void registrar_curso()
    {
        int _id, _credito;
        string _nombre;
        
        cout << "Ingrese el identificador del curso (solo numeros): " << endl;
        while (!(cin >> _id)) {
            cout << "Error. Debe ingresar un numero. Intente de nuevo: ";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }

        cout << "Ingrese el nombre del curso: " << endl;
        cin >> _nombre;
        
        cout << "Ingrese los creditos (solo numeros): " << endl;
        while (!(cin >> _credito)) {
            cout << "Error. Debe ingresar un numero. Intente de nuevo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        this->set_id(_id);
        this->set_nombre(_nombre);
        this->set_credito(_credito);
    }

    void agregar_docente()
    {
        string _dni, _nombre, _apPaterno, apMaterno;
        cout << "Ingrese el dni del docente" << endl;
        cin >> _dni;
        cout << "Ingrese el nombre del docente" << endl;
        cin >> _nombre;
        cout << "Ingrese el apellido paterno del docente" << endl;
        cin >> _apPaterno;
        cout << "Ingrese el apellido materno del docente" << endl;
        cin >> apMaterno;
        this->docente = Persona(_dni, _nombre, _apPaterno, apMaterno);
    }

    void agregar_alumno()
    {
        if (total_alumnos < 5)
        {
            string _dni, _nombre, _apPaterno, apMaterno;
            cout << "Ingrese el dni del alumno" << endl;
            cin >> _dni;
            cout << "Ingrese el nombre del alumno" << endl;
            cin >> _nombre;
            cout << "Ingrese el apellido paterno del alumno" << endl;
            cin >> _apPaterno;
            cout << "Ingrese el apellido materno del alumno" << endl;
            cin >> apMaterno;
            Persona alumno = Persona(_dni, _nombre, _apPaterno, apMaterno);
            estudiantes[total_alumnos] = alumno;
            total_alumnos++;
            
            guardar_alumnos();
            cout << "Alumno registrado y guardado exitosamente." << endl;
        }
        else
        {
            cout << "No hay capacidad para registrar mas alumnos" << endl;
        }
    }

    void listar_alumnos()
    {
        for (int i = 0; i < total_alumnos; i++)
        {
            if (estudiantes[i].get_dni() != "")
            {
                estudiantes[i].saludar();
            }
        }
    }

    void eliminar_alumno()
    {
        string _dniEliminar; 
        cout << "Ingrese el DNI del alumno a eliminar: " << endl;
        cin >> _dniEliminar;
        bool encontrado = false;
        
        for (int i = 0; i < total_alumnos; i++)
        {
            if (estudiantes[i].get_dni() == _dniEliminar)
            {
                estudiantes[i] = Persona(); 
                encontrado = true;
                cout << "Alumno eliminado." << endl;
            }
        }
        if (encontrado) {
            guardar_alumnos(); 
        } else {
            cout << "Alumno no encontrado." << endl;
        }
    }

    void imprimir()
    {
        cout << "===========================" << endl;
        cout << "Nombre del curso: " << this->nombre << endl;
        cout << "Creditos: " << this->credito << endl;
        if(docente.get_dni() != "") {
             cout << "Docente del curso: " << this->docente.get_nombre() << " " << this->docente.get_paterno() << " " << this->docente.get_materno() << endl;
        } else {
             cout << "Docente del curso: No asignado" << endl;
        }
        cout << "========Alumnos=========" << endl;
        this->listar_alumnos();
        cout << "========================" << endl;
    }


    void guardar_alumnos()
    {
        ofstream archivoSalida("Estudiante.txt");
        if (archivoSalida.is_open())
        {
            for (int i = 0; i < total_alumnos; i++)
            {
                if (estudiantes[i].get_dni() != "") {
                    archivoSalida << estudiantes[i].get_dni() << " "
                                  << estudiantes[i].get_nombre() << " "
                                  << estudiantes[i].get_paterno() << " "
                                  << estudiantes[i].get_materno() << endl;
                }
            }
            archivoSalida.close();
        }
    }

    void cargar_alumnos()
    {
        ifstream archivoEntrada("Estudiante.txt"); 
        string _dni, _nombre, _paterno, _materno;
        total_alumnos = 0; 
        
        if (archivoEntrada.is_open())
        {
            while (archivoEntrada >> _dni >> _nombre >> _paterno >> _materno)
            {
                if (total_alumnos < 5) {
                    estudiantes[total_alumnos] = Persona(_dni, _nombre, _paterno, _materno);
                    total_alumnos++;
                }
            }
            archivoEntrada.close();
            cout << "Datos de alumnos cargados correctamente." << endl;
        }
    }
};
