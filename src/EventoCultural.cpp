#include "EventoCultural.h"

// Constructor
EventoCultural::EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon) 
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) { 
    
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
}

// Getters
std::string EventoCultural::getUbicacion() const {
    return this->ubicacion;
}

bool EventoCultural::getUsoCupon() const {
    return this->usoCupon;
}

// Methods
float EventoCultural::calcularCosto() {
    int cant = this->getCantTuristas();
    float pBase = (float)this->getPrecioBase();

    float costoTotal = pBase * cant;

    if (this->usoCupon) {
        costoTotal = costoTotal - (5 * cant);
    }

    return costoTotal;
}