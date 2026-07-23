#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Persona.h"

class Administrador : public Persona
{

public:

    Administrador();

    Administrador(string nombre,
                  string usuario,
                  string contrasena);

    void mostrarMenu() override;

};

#endif

/*
herencia, poliformismo y sobreeescritura pq estamos implementando
el método virtual declarado en Persona.
*/
