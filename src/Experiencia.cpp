#include "Experiencia.h"


// Getters
int Experiencia::getCantTuristas() const {
    return this->turistas.size();
}

int Experiencia::getPrecioBase() const {
    return this->precioBase;
}

// Methods
void Experiencia::vincularTurista(Turista* t) {
    this->participantes.insert(t);
}