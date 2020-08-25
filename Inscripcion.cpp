/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inscripcion.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:24 PM
 */

#include "Inscripcion.h"

Inscripcion::Inscripcion(Fecha* fec, Socio* soc) {
    this->fecha=fec;
    this->socio=soc;
}   

Inscripcion::Inscripcion(){
    this->fecha=NULL;
    this->socio=NULL;
}

Fecha* Inscripcion::getfecha(){
    return fecha;
}

Socio* Inscripcion::getsocio(){
    return socio;
}

void Inscripcion::setFecha(Fecha *fec){
    this->fecha=fec;
}

void Inscripcion::setSocio(Socio *soc){
    this->socio=soc;
}

Inscripcion::~Inscripcion(){
    delete fecha;
}

