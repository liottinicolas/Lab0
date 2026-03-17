#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "Experiencia.h"
#include "TipoRegimen.h"
#include "DTFecha.h"

class Alojamiento : public Experiencia {
private:
    std::string hotel;
    TipoRegimen regimen;
    int cantNoches;

public:
    Alojamiento(std::string codigoReserva,
                std::string descripcion,
                float precioBase,
                DTFecha fecha,
                std::string hotel,
                TipoRegimen regimen,
                int cantNoches);

    ~Alojamiento();
    
    std::string gethotel();
    TipoRegimen getregimen();
    int getcantNoches();

    void sethotel(std::string hotel);
    void setregimen(TipoRegimen regimen);
    void setcantNoches(int cantNoches);
    
    float calcularCosto();
};

#endif
