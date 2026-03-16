#include "TourGuiado.h"

// Constructor
TourGuiado::tour(string codigoReserva, string descripcion, string agencia, <string> lugaresVisitados, int precioBase, DTFecha fecha)
    :Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha) {
    this->lugaresVisitados = lugaresVisitados;
    this->agencia = agencia;
}

// Destructor
TourGuiado::~tour()
    :~Experiencia(){}

// Setters
void TourGuiado::setagencia(){
    this->agencia = agencia;
}

void TourGuiado::setlugaresvisitados(){
    this->lugaresVisitados = lugaresVisitados;
}

// Getters
string TourGuiado::getagencia(){
    return this->agencia;
}

<string> TourGuiado::getlugaresvisitados(){
    return this->lugaresVisitados;
}

bool TourGuiado:: getestalugar(string lugar){
    return (this->lugaresVisitados.find(lugar) != this->lugaresVisitados.end(lugar));
}

int TourGuiado:: getcantlugares(){
    return this->lugaresVisitados.size;
}

// Operación abstracta
Float TourGuiado:: calcularCosto() override {
    return ((getPrecioBase() + 2) * getCantTuristas() * getcantlugares())
}