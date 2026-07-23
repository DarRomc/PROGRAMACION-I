#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona
{
protected:

    string nombre;
    string usuario;
    string contrasena;

public:

    // Constructor por defecto
    Persona();

    // Constructor con parámetros
    Persona(string nombre, string usuario, string contrasena);

    // Destructor virtual
    virtual ~Persona();

    // Getters
    string getNombre() const;
    string getUsuario() const;
    string getContrasena() const;

    // Setters
    void setNombre(string nombre);
    void setUsuario(string usuario);
    void setContrasena(string contrasena);

    // Método virtual puro
    virtual void mostrarMenu() = 0;
};

#endif

//poliformismo
