/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:29 PM
 */

#include "Clase.h"

Clase::Clase(int id, string nombre, Turno turno){
    this->id=id;
    this->nombre=nombre;
    this->turno=turno;
    
    int a;
    for (a=0;a<50;a++)
        this->inscripciones[a] =NULL;
}

Clase::Clase(){
    this->id=0;
    this->nombre="No disponible";
    this->turno;
}
//getters
int Clase::getId(){
  return id;
}

string Clase::getNombre(){
  return nombre;
}

Turno Clase::getTurno(){
    return turno;
}

Inscripcion** Clase::getInscripciones(){
    return this->inscripciones;
}

int Clase::CantInscripciones(){
    int res = 0;
    Inscripcion** ins = this->inscripciones;
    for (int i=0;i<50;i++){
        if (ins[i]!=NULL)
            res++;
    }
    return res;
 }

//setters

void Clase::addInscripcion(Socio* s, Fecha* f, int max, string ci){
    for(int i = 0; i < max; i++)
    {
        if (inscripciones[i] != NULL && inscripciones[i]->getsocio()->getCi() == ci)
        {
            throw invalid_argument("Esta inscripcion ya existe");
        }
    }
    Inscripcion* insc = new Inscripcion(f,s);
    int i = 0;
    for (i=0;i<50;i++){
        if(this->inscripciones[i]==NULL){
            inscripciones[i]=insc;
            break;
        }
    }
    if (i==50)
        cout<<"No se puede inscribir mas";
}

void Clase::borrarInsc(int max, string ci){
    bool control=false;
    for (int i= 0; i<max;i++){
        if(inscripciones[i] != NULL && inscripciones[i]->getsocio()->getCi()==ci){
            delete inscripciones[i];
            inscripciones[i]=NULL;
            control=true;
            cout<<"La inscripcion se ha borrado satisfactoriamente"<<endl<<endl;
            break;
        }
           
    }
    if(!control){
        throw invalid_argument("Esta inscripcion no existe");
    }
}

DtSocio** Clase::obtenerInfo(int& cantSoc, int max){
    int posicion=0;
    //cantSoc=0;
    for(int i=0;i<max;i++){
        if(inscripciones[i] != NULL){
            cantSoc++;
        }
    }
    if(cantSoc==0){
        throw invalid_argument ("Esta clase no tiene inscripciones");
    }
    DtSocio** soc = (DtSocio**) malloc(sizeof (DtSocio) * cantSoc);
    for(int i=0;i<max;i++){
        if(inscripciones[i]!=NULL){
            soc[posicion]=new DtSocio(inscripciones[i]->getsocio()->getCi(), inscripciones[i]->getsocio()->getNombre(), 
                    new Fecha(inscripciones[i]->getfecha()->getDia(), inscripciones[i]->getfecha()->getMes(), inscripciones[i]->getfecha()->getAnio()));
            posicion++;
        }
    }
    return soc;
}

void Clase::setId(int i){
    this->id=i;
}

void Clase::setNombre(string nomb){
    this->nombre=nomb;
}

void Clase::setTurno(Turno tur){
    this->turno=tur;
}

//destructor

Clase::~Clase(){
}
