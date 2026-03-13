#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include <set>
#include <ostream>
#include "DTFecha.h"

class DTExpe {
private:
    // Attributes 
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;

public:
    // Constructor
    DTExpe(std::string codigo, std::string desc, DTFecha f, std::set<std::string> tur);

    // Getters
    std::string getCodigoReserva() const;
    std::string getDescripcion() const;
    DTFecha getFecha() const;
    std::set<std::string> getTuristas() const;

    // Overload
    friend std::ostream& operator<<(std::ostream& os, const DTExpe& dt);
};

#endif