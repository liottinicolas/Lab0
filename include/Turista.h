#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include "DTFecha.h"

class Experiencia;

class Turista {
private:
    std::string ci;
    std::string nombre;
    std::string email;
    
    std::list<Experiencia*> experiencias;

public:
    std::string toString();
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
};

#endif
