#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    bool operator<(const DTFecha& fecha2) const;
    bool operator>(const DTFecha& fecha2) const;
    bool operator==(const DTFecha& fecha2) const;
    bool operator!=(const DTFecha& fecha2) const;
    bool operator<=(const DTFecha& fecha2) const;
    bool operator>=(const DTFecha& fecha2) const;
    DTFecha avanzar(int cantDias) const;
};

#endif
