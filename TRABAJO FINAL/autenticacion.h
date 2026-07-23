#ifndef AUTENTICACION_H
#define AUTENTICACION_H

#include <string>

using namespace std;

class Autenticacion
{
private:

    int intentos;

    const int MAX_INTENTOS = 3;

public:

    Autenticacion();

    bool iniciarSesion(string usuario,
                       string contrasena,
                       bool &esAdministrador);

};

#endif
