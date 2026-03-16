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
    // Constructor
    tour(string codigoReserva, string descripcion, string agencia, <string> lugaresVisitados, int precioBase, DTFecha fecha);

    // Destructor
    ~tour();

    // Setters
    void setagencia(string agencia);
    void setlugaresvisitados(<string> lugaresVisitados);
    void setlugarvisitado(string lugarvisitado);

    // Getters
    string getagencia();
    <string> getlugaresvisitados();
    bool getestalugar(string lugar);
    int getcantlugares();

    float calcularCosto() override;
};

#endif
