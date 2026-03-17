#include "TourGuiado.h"
#include "DTFecha.h"
#include "Experiencia.h"
#include <set>
#include <string>

using namespace std;

// Constructor
TourGuiado::TourGuiado(string codigoReserva, string descripcion, string agencia,
                       set<string> lugaresVisitados, int precioBase,
                       DTFecha fecha)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
  this->lugaresVisitados = lugaresVisitados;
  this->agencia = agencia;
}

// Destructor
TourGuiado::~TourGuiado() {}

// Setters
void TourGuiado::setagencia(string agencia) { this->agencia = agencia; }

void TourGuiado::setlugaresvisitados(set<string> lugaresVisitados) {
  this->lugaresVisitados = lugaresVisitados;
}

// Getters
string TourGuiado::getagencia() { return this->agencia; }

set<string> TourGuiado::getlugaresvisitados() { return this->lugaresVisitados; }

bool TourGuiado::getestalugar(string lugar) {
  return (this->lugaresVisitados.find(lugar) != this->lugaresVisitados.end());
}

int TourGuiado::getcantlugares() { return this->lugaresVisitados.size(); }

// Operación abstracta
float TourGuiado::calcularCosto() {
  return ((getPrecioBase() + 2) * getCantTuristas() * getcantlugares());
}