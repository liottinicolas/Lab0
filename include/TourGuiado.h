#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include <string>
#include <set>
#include "Experiencia.h"

class TourGuiado : public Experiencia {
private:
    std::string agencia;
    std::set<std::string> lugaresVisitados;
public:
    float calcularCosto() override;
};

#endif
