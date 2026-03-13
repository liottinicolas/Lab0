#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int Dia;
    int Mes;
    int Anio;

public:
    // Constructor
    DTFecha(int Dia, int Mes, int Anio);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif