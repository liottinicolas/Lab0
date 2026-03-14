#include "DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
int DTFecha::getDia() const{
    return this->dia;
}
int DTFecha::getMes() const{
    return this->mes;
}
int DTFecha::getAnio() const{
    return this->anio;
}
bool DTFecha::operator<(const Fecha& fecha2) const{
    bool esMenor = false;
    if(this->anio < fecha2.getAnio()){
        esMenor = true;
    }else if(this->anio == fecha2.getAnio() && this->mes < fecha2.getMes()){
        esMenor = true;
    }else if(this->anio == fecha2.getAnio() && this->mes == fecha2.getMes() && this->dia < fecha2.getDia()){
        esMenor = true;
    }
    return esMenor;
}
bool DTFecha::operator>(const Fecha& fecha2) const{
    bool esMayor = false;
    if(fecha2<*this /*&& fecha2.getAnio() != this->anio && fecha2.getMes() != this->mes && fecha2.getDia() != this->dia*/){
        esMayor = true;
    }
    return esMayor;
}
bool DTFecha::operator==(const Fecha& fecha2) const{
    bool sonIguales = false;
    if(fecha2.getAnio() == this->anio && fecha2.getMes() == this->mes && fecha2.getDia() == this->dia){
        sonIguales = true;
    }
    return sonIguales;
}
bool DTFecha::operator!=(const Fecha& fecha2) const{
    bool sonDistintos = !(*this==fecha2);
    return sonDistintos;
}
bool DTFecha::operator<=(const Fecha& fecha2) const{
    bool sonMenorIgual = false;
    if(*this<fecha2 || *this==fecha2){
        sonMenorIgual = true;
    }
    return sonMenorIgual;
}
bool DTFecha::operator>=(const Fecha& fecha2) const{
    bool esMayorIgual = false;
    if(*this>fecha2 || *this==fecha2){
        esMayorIgual = true;
    }
    return esMayorIgual;
}
Fecha DTFecha::avanzar(int cantDias) const{
    Fecha fechaAvanzada(this->dia,this->mes,this->anio);
    bool terminar = false;
    fechaAvanzada.dia += cantDias;
    while(!terminar){
        switch (fechaAvanzada.getMes())
        {
        case 1:case 3: case 5: case 7: case 8:case 10: case 12:
            if(fechaAvanzada.getDia() > 31){
                if(fechaAvanzada.getMes() == 12){
                    fechaAvanzada.anio++;
                    fechaAvanzada.mes = 1;
                    fechaAvanzada.dia = fechaAvanzada.getDia()-31;
                }else{
                    fechaAvanzada.mes++;
                    fechaAvanzada.dia = fechaAvanzada.getDia()-31;
                }
            }else{
                terminar = true;
            }
            break;
        case 4:case 6: case 9: case 11:
            if(fechaAvanzada.getDia() > 30){
                fechaAvanzada.mes++;
                fechaAvanzada.dia = fechaAvanzada.getDia()-30;
            }else{
                terminar = true;
            }
            break;
        case 2:
            int cantDiasBisiesto = 28;
            if((fechaAvanzada.anio % 4 == 0 && fechaAvanzada.anio % 100 != 0) || fechaAvanzada.anio % 400 == 0 /*(fechaAvanzada->anio)%100 == 0 && (fechaAvanzada->anio)%400 != 0*/){
                cantDiasBisiesto = 29;
            }
            /*if((fechaAvanzada->anio)%4 != 0){
                cantDiasBisiesto = 29;
            }*/
            if(fechaAvanzada.getDia() > cantDiasBisiesto){
                fechaAvanzada.mes++;
                fechaAvanzada.dia = fechaAvanzada.getDia()-cantDiasBisiesto;
            }else{
                terminar = true;
            }
            break;
        default:
            break;
        }
    }
    return fechaAvanzada;
}
