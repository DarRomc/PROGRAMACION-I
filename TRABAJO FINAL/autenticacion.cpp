#include "Autenticacion.h"
#include "Logger.h"

#include <iostream>

using namespace std;

//====================================================
// Constructor
//====================================================

Autenticacion::Autenticacion()
{
    intentos = 0;
}

//====================================================
// Inicio de sesión
//====================================================

bool Autenticacion::iniciarSesion(string usuario,
                                  string contrasena,
                                  bool &esAdministrador)
{

    if(intentos >= MAX_INTENTOS)
    {
        Logger::registrar("Acceso bloqueado por exceso de intentos.");

        cout << "\n====================================";
        cout << "\nSISTEMA BLOQUEADO";
        cout << "\nDemasiados intentos fallidos.";
        cout << "\n====================================\n";

        return false;
    }

    //------------------------------------------------
    // Administrador
    //------------------------------------------------

    if(usuario=="admin"
       && contrasena=="admin123")
    {
        esAdministrador=true;

        intentos=0;

        return true;
    }

    //------------------------------------------------
    // Usuario
    //------------------------------------------------

    if(usuario=="usuario"
       && contrasena=="user123")
    {
        esAdministrador=false;

        intentos=0;

        return true;
    }

    //------------------------------------------------
    // Error
    //------------------------------------------------

    intentos++;

    Logger::registrar("Intento fallido de inicio de sesión.");

    cout << "\nUsuario o contraseña incorrectos.";

    cout << "\nIntento "
         << intentos
         << " de "
         << MAX_INTENTOS
         << endl;

    return false;

}
