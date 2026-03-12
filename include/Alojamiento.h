#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "Experiencia.h"
#include "TipoRegimen.h"

class Alojamiento : public Experiencia {
private:
    std::string hotel;
    TipoRegimen regimen;
    int cantNoches;
public:
    float calcularCosto() override;
};

#endif
