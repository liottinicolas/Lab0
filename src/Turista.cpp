#include "Turista.h"
#include <string>
#include <set>
#include <list>
#include "DTFecha.h"

using namespace std;

class Experiencia;

Turista::Turista(string ci,string nombre,string email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}
string Turista::getCi(){
    return this->ci;
}
string Turista::getNombre(){
    return this->nombre;
}
string Turista::getEmail(){
    return this->email;
}
void Turista::setCi(string ci){
    this->ci = ci;
}
void Turista::setNombre(string nombre){
    this->nombre = nombre;
}
void Turista::setEmail(string email){
    this->email = email;
}
void Turista::setParticipa(Experiencia* experiencia_agregar){
    if(this->participa.empty()){
        this->participa.push_front(experiencia_agregar);
    }else{
        list<Experiencia*>::iterator aux_experiencia = this->participa.begin();
        while(aux_experiencia != this->participa.end() && (*experiencia_agregar).getFecha()<=(*aux_experiencia)->getFecha()){
            ++aux_experiencia;
        }
        this->participa.insert(aux_experiencia,experiencia_agregar);
    }
    experiencia_agregar->vincularTurista(this);
}
string Turista::toString(){
    string nombre_email = string(this->getCi())+"->"+string(this->getNombre())+"/"+string(this->getEmail());
    return nombre_email;
}
set<string> Turista::listarExperiencias(DTFecha desde,float min,float max){
    set<string> experiencias_desde;
    list<Experiencia*>::iterator aux_participa = this->participa.begin();
    while(aux_participa != this->participa.end() && (*aux_participa)->getFecha()>=desde){
        if((*aux_participa)->getPrecioBase() <= max && (*aux_participa)->getPrecioBase() >= min){
            experiencias_desde.insert((*aux_participa)->getCodigoReserva());
        }
        ++aux_participa;
    }
    return experiencias_desde;
}
void Turista::eliminarExperiencia(Experiencia* experiencia_eliminar){
    this->participa.remove(experiencia_eliminar);
}

Turista::~Turista() {}