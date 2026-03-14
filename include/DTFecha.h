#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int Dia;
    int Mes;
    int Anio;

public:
    DTFecha(int Dia, int Mes, int Anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    bool operator<(const Fecha& fecha2) const;
    bool operator>(const Fecha& fecha2) const;
    bool operator==(const Fecha& fecha2) const;
    bool operator!=(const Fecha& fecha2) const;
    bool operator<=(const Fecha& fecha2) const;
    bool operator>=(const Fecha& fecha2) const;
    Fecha avanzar(int cantDias) const;
};

#endif
