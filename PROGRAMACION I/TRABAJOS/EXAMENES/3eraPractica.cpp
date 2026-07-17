//Codigo del caso de la practica 3.

#include <iostream>
#include <string>
using namespace std;

class IInspeccionable {
public:
    virtual void inspeccionar() = 0;
    virtual ~IInspeccionable() {}
};

//Clase abstracta
class Vehiculo : public IInspeccionable {
private:
    string placa;
    string marca, modelo;
    int anio;
    double tarifa;

public:
    Vehiculo(string p, string m, string mo, int a, double t) : placa(p), marca(m), modelo(mo), tarifa(t) {
        anio = (a < 1900 || a > 2026) ? 2026 : a;
    }

    string getPlaca() const { return placa; }
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    virtual double calcularCosto(int dias) = 0;

    virtual void mostrarInformacion() {
        cout << "Placa: " << placa << " | " << marca << " " << modelo << " (" << anio << ")" << endl;
    }
};

// CLASES DERIVADAS
class Automovil : public Vehiculo {
public:
    Automovil(string p, string m, string mo, int a, double t) : Vehiculo(p, m, mo, a, t) {}
    
    double calcularCosto(int dias) override { return dias * 50.0; } // Costo base
    void inspeccionar() override { cout << "Inspeccionando puertas y cinturones del automovil " << getPlaca() << endl; }
};

class Motocicleta : public Vehiculo {
public:
    Motocicleta(string p, string m, string mo, int a, double t) : Vehiculo(p, m, mo, a, t) {}
    
    double calcularCosto(int dias) override { return (dias * 30.0) * 0.9; } // 10% descuento
    void inspeccionar() override { cout << "Inspeccionando frenos y cadena de la moto " << getPlaca() << endl; }
};

class Camioneta : public Vehiculo {
public:
    Camioneta(string p, string m, string mo, int a, double t) : Vehiculo(p, m, mo, a, t) {}
    
    double calcularCosto(int dias) override { return (dias * 80.0) + 20.0; } // +20 recargo carga
    void inspeccionar() override { cout << "Inspeccionando carroceria y carga de la camioneta " << getPlaca() << endl; }
};

//Funcion main / aplicacion del polimorfismo.
int main() {
    vector<Vehiculo*> flota;

    flota.push_back(new Automovil("ABC-123", "Toyota", "Corolla", 2024, 50));
    flota.push_back(new Motocicleta("MOT-999", "Honda", "CB500", 2025, 30));
    flota.push_back(new Camioneta("CAM-777", "Ford", "Ranger", 2023, 80));

    for (Vehiculo* v : flota) {
        v->mostrarInformacion();
        v->inspeccionar();
        cout << "Costo total alquiler (3 dias): S/" << v->calcularCosto(3) << endl;
        cout << "-----------------------------------" << endl;
    }
    for (Vehiculo* v : flota) delete v;

    return 0;
}
