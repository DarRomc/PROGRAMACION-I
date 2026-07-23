#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"

class Usuario : public Persona
{

public:

    Usuario();

    Usuario(string nombre,
             string usuario,
             string contrasena);

    void mostrarMenu() override;

};

#endif
