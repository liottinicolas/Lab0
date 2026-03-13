#include "DTFecha.h"

// Constructor
DTFecha::DTFecha(int Dia, int Mes, int Anio) {
    this->Dia = Dia;
    this->Mes = Mes;
    this->Anio = Anio;
}

// Getters
int DTFecha::getDia() const { 
    return this->Dia; 
}

int DTFecha::getMes() const { 
    return this->Mes; 
}

int DTFecha::getAnio() const { 
    return this->Anio; 
}