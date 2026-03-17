#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include <list>
#include "Experiencia.h"
#include "DTFecha.h"

using namespace std;

class Experiencia;

class Turista {
private:
    std::string ci;
    std::string nombre;
    std::string email;
    std::list<Experiencia*> participa;

public:
    Turista(string ci,string nombre,string email);
    string getCi();
    string getNombre();
    string getEmail();
    void setCi(string ci);
    void setNombre(string nombre);
    void setEmail(string email);
    void setParticipa(Experiencia* experiencia_agregar);
    void eliminarExperiencia(Experiencia* experiencia_eliminar);
    std::string toString();
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
    virtual ~Turista();
};

#endif
