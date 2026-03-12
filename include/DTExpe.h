#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include <set>
#include "DTFecha.h"

class DTExpe {
private:
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;
};

#endif
