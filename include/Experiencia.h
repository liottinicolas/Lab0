#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTExpe.h"

class Turista;

class Experiencia {
private:
    // Atributos
    string codigoReserva;
    string descripcion;
    int precioBase;
    DTFecha fecha;
    
    // Pseudo Atributos
    set<Turista*> participantes;

public:
    // Constructor
    Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha);

    // Getters

    string getCodigoReserva() const;
    string getDescripcion() const;
    DTFecha getFecha() const;
    int getPrecioBase() const;
    int getCantTuristas() const;

    // Setters
    void setCodigoReserva(string codigoReserva);
    void setDescripcion(string descripcion);
    void setPrecioBase(int precioBase);
    void setFecha(DTFecha fecha);

    // Metodos
    virtual DTExpe getDT();
    virtual float calcularCosto() = 0;
    void vincularTurista(Turista* t);
    virtual ~Experiencia();
    
};

#endif
