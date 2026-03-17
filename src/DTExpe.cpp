#include "DTExpe.h"

// Constructor
DTExpe::DTExpe(std::string codigoReserva, std::string descripcion, DTFecha fecha, std::set<std::string> turistas) 
    : codigoReserva(codigoReserva), descripcion(descripcion), fecha(fecha), turistas(turistas) {
}

// Getters
std::string DTExpe::getCodigoReserva() const { 
    return this->codigoReserva; 
}
std::string DTExpe::getDescripcion() const { 
    return this->descripcion; 
}
DTFecha DTExpe::getFecha() const { 
    return this->fecha; 
}
std::set<std::string> DTExpe::getTuristas() const { 
    return this->turistas; 
}

// Overload
std::ostream& operator<<(std::ostream& os, const DTExpe& dt) {
    
    os << dt.codigoReserva << "->" << dt.descripcion << " (";
    
    os << dt.fecha.getDia() << "/" << dt.fecha.getMes() << "/" << dt.fecha.getAnio() << ")/";
    
    std::set<std::string>::const_iterator it;
    bool primerTurista = true; 
    
    for (it = dt.turistas.begin(); it != dt.turistas.end(); ++it) {
       
        if (!primerTurista) {
            os << ", "; 
        }
        os << *it; 
        primerTurista = false;
    }
    
    return os;
}