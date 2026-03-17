#include "Experiencia.h"
#include "Turista.h"


// Constructor
Experiencia::Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}

// Getters

string Experiencia::getCodigoReserva() const {
    return this->codigoReserva;
}

string Experiencia::getDescripcion() const {
    return this->descripcion;
}

DTFecha Experiencia::getFecha() const {
    return this->fecha;
}
int Experiencia::getCantTuristas() const {
    return this->participantes.size();
}

int Experiencia::getPrecioBase() const {
    return this->precioBase;
}

// Setters
void Experiencia::setCodigoReserva(string codigoReserva) {
    this->codigoReserva = codigoReserva;
}

void Experiencia::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Experiencia::setPrecioBase(int precioBase) {
    this->precioBase = precioBase;
}

void Experiencia::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void Experiencia::vincularTurista(Turista* t) {
    this->participantes.insert(t);
}

// Metodos
DTExpe Experiencia::getDT() {
    std::set<std::string> infoTuristas;
    for (Turista* t : this->participantes) {
        infoTuristas.insert(t->toString()); 
    }
    return DTExpe(this->codigoReserva, this->descripcion, this->fecha, infoTuristas);
}

Experiencia::~Experiencia() {
    std::set<Turista*>::iterator it;
    for(it = participantes.begin();it != participantes.end();++it){
        (*it)->eliminarExperiencia(this);
    }
    this->participantes.clear();
}
