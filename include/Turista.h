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
    Turista(String ci,String nombre,String email);
    String getCi();
    String getNombre();
    String getEmail();
    void setNombre(String nombre);
    void setEmail(String email);
    void setParticipa(const Experiencia& experiencia_agregar);
    std::string toString();
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
};

#endif
