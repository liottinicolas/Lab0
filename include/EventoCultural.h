#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include <string>
#include "Experiencia.h"

class EventoCultural : public Experiencia {
private:
    std::string ubicacion;
    bool usoCupon;
public:
    float calcularCosto() override;
};

#endif
