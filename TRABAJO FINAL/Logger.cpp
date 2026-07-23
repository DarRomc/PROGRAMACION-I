#include "Logger.h"

#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

void Logger::registrar(const string& mensaje)
{
    ofstream archivo("log.txt", ios::app);

    if (!archivo)
        return;

    time_t ahora = time(nullptr);

    tm* tiempo = localtime(&ahora);

    archivo << "=========================================\n";
    archivo << "Fecha : "
            << put_time(tiempo, "%d/%m/%Y") << endl;

    archivo << "Hora  : "
            << put_time(tiempo, "%H:%M:%S") << endl;

    archivo << "Evento: "
            << mensaje << endl;

    archivo << "=========================================\n\n";

    archivo.close();
}
