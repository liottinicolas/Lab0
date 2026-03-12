#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTExpe.h"

class Turista;

class Experiencia {
private:
    std::string codigoReserva;
    std::string descripcion;
    int precioBase;
    DTFecha fecha;
    
    // Relación bidireccional "Participa en"
    std::set<Turista*> turistas;

public:
    virtual DTExpe getDT();
    virtual float calcularCosto() = 0; // Método abstracto (en cursiva en UML)
    virtual ~Experiencia() = default;
};

#endif
