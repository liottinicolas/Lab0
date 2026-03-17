#include <iostream>
#include <list>
#include <map>

#include "Alojamiento.h"
#include "DTExpe.h"
#include "DTFecha.h"
#include "EventoCultural.h"
#include "Experiencia.h"
#include "TourGuiado.h"
#include "Turista.h"

// --- Colecciones globales
std::list<Experiencia *> experiencias;
std::map<std::string, Experiencia *> map_experiencias;

std::list<Turista *> turistas;
std::map<std::string, Turista *> map_turistas;

// Funciones auxiliares
void coleccion_guardarExperiencia(Experiencia *exp) {
  experiencias.push_back(exp);
  std::pair<std::string, Experiencia *> entry(exp->getCodigoReserva(), exp);
  map_experiencias.insert(entry);
}

void coleccion_eliminarExperiencia(Experiencia *exp) {
  experiencias.remove(exp);
  map_experiencias.erase(exp->getCodigoReserva());
}

void coleccion_guardarTurista(Turista *tur) {
  turistas.push_back(tur);
  std::pair<std::string, Turista *> entry(tur->getCi(), tur);
  map_turistas.insert(entry);
}

Turista *coleccion_getTurista(std::string ci) { return map_turistas[ci]; }

Experiencia *coleccion_getExperiencia(std::string codigoReserva) {
  return map_experiencias[codigoReserva];
}
void parte_a() {
  DTFecha f1(18, 5, 2020);
  Alojamiento *al1 = new Alojamiento("ALX5489", "Hotel moderno", 30, f1,
                                     "Hotel Lindorf", AllInclusive, 5);

  DTFecha f2(10, 2, 2025);
  Alojamiento *al2 =
      new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100,
                      f2, "Hotel Sea View", MediaPension, 15);

  coleccion_guardarExperiencia(al1);
  coleccion_guardarExperiencia(al2);
}

void parte_b() {
  std::set<std::string> lugares1;
  lugares1.insert("Plaza Independencia");
  lugares1.insert("Plaza Matriz");
  DTFecha f3(29, 8, 2024);
  TourGuiado *tg1 = new TourGuiado("TGO4657", "Plazas de Montevideo",
                                   "Paseos SA", lugares1, 10, f3);

  std::set<std::string> lugares2;
  lugares2.insert("Puerta de la Ciudadela");
  lugares2.insert("Mausoleo");
  lugares2.insert("Cabildo");
  lugares2.insert("Palacio Salvo");
  DTFecha f4(29, 8, 2024);
  TourGuiado *tg2 = new TourGuiado("TGR3257", "Puntos emblematicos", "Recorre",
                                   lugares2, 5, f4);

  coleccion_guardarExperiencia(tg1);
  coleccion_guardarExperiencia(tg2);
}

void parte_c() {
  DTFecha f5(29, 10, 2025);
  EventoCultural *ec1 = new EventoCultural("ECP1346", "Danza en el Solis", 10,
                                           f5, "Teatro Solis", true);

  coleccion_guardarExperiencia(ec1);
}

void parte_d() {
  std::list<Experiencia *>::iterator it;
  for (it = experiencias.begin(); it != experiencias.end(); ++it) {
    DTExpe dt = (*it)->getDT();
    std::cout << dt << std::endl;
  }
}

void parte_e() {
  Turista *t1 =
      new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
  Turista *t2 =
      new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");

  coleccion_guardarTurista(t1);
  coleccion_guardarTurista(t2);
}

void parte_f() {
  std::list<Turista *>::iterator it;
  for (it = turistas.begin(); it != turistas.end(); ++it) {
    std::cout << (*it)->toString() << std::endl;
  }
}

void parte_g() {
  Turista *vanesa = coleccion_getTurista("4.951.278-9");
  Turista *karen = coleccion_getTurista("1.535.442-0");

  Experiencia *al1 = coleccion_getExperiencia("ALX5489");
  Experiencia *al2 = coleccion_getExperiencia("ALJ4789");
  Experiencia *tg1 = coleccion_getExperiencia("TGO4657");
  Experiencia *tg2 = coleccion_getExperiencia("TGR3257");
  Experiencia *ec1 = coleccion_getExperiencia("ECP1346");

  if (vanesa && al1 && al2 && tg2 && ec1) {
    vanesa->setParticipa(al1);
    vanesa->setParticipa(al2);
    vanesa->setParticipa(tg2);
    vanesa->setParticipa(ec1);
  }

  if (karen && tg1 && tg2) {
    karen->setParticipa(tg1);
    karen->setParticipa(tg2);
  }

  /* ...
  std::cout << "Relaciones creadas exitosamente." << std::endl;*/
}

void parte_h() {
  Turista *vanesa = coleccion_getTurista("4.951.278-9");

  if (vanesa != NULL) {
    DTFecha desde(10, 12, 2023);

    std::set<std::string> listExp = vanesa->listarExperiencias(desde, 0, 1000);

    std::cout
        << "--- Experiencias de Vanesa Castro posteriores al 10/12/2023 ---"
        << std::endl;

    std::set<std::string>::iterator it;
    for (it = listExp.begin(); it != listExp.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
}

void parte_i() {
  Experiencia *exp = coleccion_getExperiencia("TGR3257");

  if (exp != NULL) {
    coleccion_eliminarExperiencia(exp);

    delete exp;
    std::cout << "Experiencia TGR3257 eliminada con exito." << std::endl;
  }
}

void parte_j() {
  Turista *karen = coleccion_getTurista("1.535.442-0");

  if (karen != NULL) {
    DTFecha desde(10, 10, 2020);
    std::set<std::string> listExp = karen->listarExperiencias(desde, 0, 1000);

    std::cout << "--- Experiencias de Karen Santos ---" << std::endl;

    std::set<std::string>::iterator it;
    for (it = listExp.begin(); it != listExp.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
}

void parte_k() {
  std::cout << "--- Listado de Experiencias (Final) ---" << std::endl;

  std::list<Experiencia *>::iterator it;
  for (it = experiencias.begin(); it != experiencias.end(); ++it) {
    DTExpe dt = (*it)->getDT();
    std::cout << dt << std::endl;
  }
}

void cleanUp() {}

int main() {
  std::cout << "parte_a" << std::endl;
  parte_a();
  std::cout << "parte_b" << std::endl;
  parte_b();
  std::cout << "parte_c" << std::endl;
  parte_c();
  std::cout << "parte_d" << std::endl;
  parte_d();
  std::cout << "parte_e" << std::endl;
  parte_e();
  std::cout << "parte_f" << std::endl;
  parte_f();
  std::cout << "parte_g" << std::endl;
  parte_g();
  std::cout << "parte_h" << std::endl;
  parte_h();
  std::cout << "parte_i" << std::endl;
  parte_i();
  std::cout << "parte_j" << std::endl;
  parte_j();
  std::cout << "parte_k" << std::endl;
  parte_k();
  std::cout << "cleanUp" << std::endl;
  cleanUp();
  std::cout << "fin" << std::endl;

  return 0;
}