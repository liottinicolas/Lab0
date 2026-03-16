#include "Alojamiento.h"
#include "DTFecha.h"
#include "Experiencia.h"
#include <string>

using namespace std;

// Constructor
Alojamiento::Alojamiento(string codigoReserva, string descripcion, float precioBase, DTFecha fecha,
string hotel, TipoRegimen regimen, int cantNoches)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}

// Destructor
Alojamiento::~Alojamiento(){}

// Getters
string Alojamiento::gethotel(){
    return this->hotel;
}

TipoRegimen Alojamiento::getregimen(){
    return this->regimen;
}

int Alojamiento::getcantNoches(){
    return this->cantNoches;
}

// Setters
void Alojamiento::sethotel(string hotel) {
    this->hotel = hotel;
}

void Alojamiento::setregimen(TipoRegimen regimen) {
    this->regimen = regimen;
}

void Alojamiento::setcantNoches(int cantNoches) {
    this->cantNoches = cantNoches;
}

// Metodo
float Alojamiento::calcularCosto() {
    float res;

    if (getregimen() == AllInclusive) {
        res = (getPrecioBase() * getcantNoches()) + 10 * getcantNoches();
    } 
    else {
        res = (getPrecioBase() * getcantNoches());
    }

    return res;
}