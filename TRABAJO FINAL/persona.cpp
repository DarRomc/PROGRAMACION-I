#include "Persona.h"

Persona::Persona()
{
    nombre = "";
    usuario = "";
    contrasena = "";
}

Persona::Persona(string nombre, string usuario, string contrasena)
{
    this->nombre = nombre;
    this->usuario = usuario;
    this->contrasena = contrasena;
}

Persona::~Persona()
{

}

string Persona::getNombre() const
{
    return nombre;
}

string Persona::getUsuario() const
{
    return usuario;
}

string Persona::getContrasena() const
{
    return contrasena;
}

void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Persona::setUsuario(string usuario)
{
    this->usuario = usuario;
}

void Persona::setContrasena(string contrasena)
{
    this->contrasena = contrasena;
}
