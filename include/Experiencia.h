#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include "DTExpe.h"
#include "DTFecha.h"

class Turista;

class Experiencia {
private:
  // Atributos
  std::string codigoReserva;
  std::string descripcion;
  int precioBase;
  DTFecha fecha;

  // Pseudo Atributos
  std::set<Turista *> participantes;

public:
  // Constructor
  Experiencia(std::string codigoReserva, std::string descripcion,
              int precioBase, DTFecha fecha);

  // Getters

  std::string getCodigoReserva() const;
  std::string getDescripcion() const;
  DTFecha getFecha() const;
  int getPrecioBase() const;
  int getCantTuristas() const;

  // Setters
  void setCodigoReserva(std::string codigoReserva);
  void setDescripcion(std::string descripcion);
  void setPrecioBase(int precioBase);
  void setFecha(DTFecha fecha);

  // Metodos
  virtual DTExpe getDT();
  virtual float calcularCosto() = 0;
  void vincularTurista(Turista *t);
  virtual ~Experiencia();
};

#endif
