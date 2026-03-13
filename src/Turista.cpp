#include "Turista.h"
#include <set>
#include <String>

using namespace std;

Class Turista(
    private:
        String ci;
        String nombre;
        String email;
        list<Experiencia*> participa;
    public:
        Turista(String ci,String nombre,String email){
            this->ci = ci;
            this->nombre = nombre;
            this->email = email;
            this->participa = NULL;
        }
        String Turista::getCi(){
            return this->ci;
        }
        String Turista::getNombre(){
            return this->nombre;
        }
        String Turista::getEmail(){
            return this->email;
        }
        void Turista::setCi(String ci){
            this->ci = ci;
        }
        void Turista::setNombre(String nombre){
            this->nombre = nombre;
        }
        void Turista::setEmail(String email){
            this->email = email;
        }
        void Turista::setParticipa(const Experiencia& experiencia_agregar){
            Experiencia* exp = (Experiencia*)&experiencia_agregar;
            if(this->participa.empty()){
                this->participa.push_front(exp);
            }else{
                list<Experiencia*>::iterator aux_experiencia = this->participa.begin();
                while(aux_experiencia != this->participa.end() && experiencia_agregar.getFecha()<=(*aux_experiencia)->getFecha()){
                    ++aux_experiencia;
                }
                this->participa.insert(aux_experiencia,exp);
            }
        }
        String Turista::toString(){
            String nombre_email = String(this->getCi())+"->"+String(this->getNombre())+"/"+String(this->getEmail());
            return nombre_email;
        }
        set<String> Turista::listarExperiencias(DTFecha desde,float min,float max){
            set<String> experiencias_desde;
            list<Experiencia*>::iterator aux_participa = this->participa.begin();
            while(aux_participa != this->participa.end() && (*aux_participa)->getFecha()>=desde){
                if((*aux_participa)->getPrecioBase() <= max && (*aux_participa)->getPrecioBase() >= min){
                    experiencias_desde.insert((*aux_participa)->getCodigoReserva());
                }
                ++aux_participa;
            }
            return experiencias_desde;
        }
}
