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
    
    std::set<Turista*> turistas;

public:
    virtual DTExpe getDT();
    virtual float calcularCosto() = 0;
    virtual ~Experiencia();
};

#endif
