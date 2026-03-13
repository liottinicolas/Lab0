#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTExpe.h"

class Turista;

class Experiencia {
private:
    // Attributes
    std::string codigoReserva;
    std::string descripcion;
    int precioBase;
    DTFecha fecha;
    
    // Pseudo Attributes
    std::set<Turista*> turistas;
    std::set<Turista*> participantes;

public:
    // Getters 
    int getCantTuristas() const;
    int getPrecioBase() const;
    virtual DTExpe getDT();

    // Methods
    virtual float calcularCosto() = 0;
    virtual ~Experiencia();
    void vincularTurista(Turista* t);
};

#endif
