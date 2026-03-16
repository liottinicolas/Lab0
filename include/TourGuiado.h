#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include <string>
#include <set>
#include "Experiencia.h"

using namespace std;

class TourGuiado : public Experiencia {
private:
    std::string agencia;
    std::set<std::string> lugaresVisitados;
public:
    // Constructor
    TourGuiado(string codigoReserva, string descripcion, string agencia, set<std::string> lugaresVisitados, int precioBase, DTFecha fecha);

    // Destructor
    ~TourGuiado();

    // Setters
    void setagencia(string agencia);
    void setlugaresvisitados(set<std::string> lugaresVisitados);
    void setlugarvisitado(std::string lugarvisitado);

    // Getters
    string getagencia();
    set<string> getlugaresvisitados();
    bool getestalugar(string lugar);
    int getcantlugares();

    float calcularCosto() override;
};

#endif
