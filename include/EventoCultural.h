#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include <string>
#include "Experiencia.h"

class EventoCultural : public Experiencia {
private:
    // Attributes 
    std::string ubicacion;
    bool usoCupon;

public:
    // Constructor
    EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon);

    // Getters
    std::string getUbicacion() const;
    bool getUsoCupon() const;

    // Virtual Method
    float calcularCosto();
};

#endif