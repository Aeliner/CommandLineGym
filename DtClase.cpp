/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtClase.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:37 PM
 */

#include "DtClase.h"

DtClase::DtClase(int id, string nom, Turno turno, int cupo, int ins){
    this->id=id;
    this->nombre=nom;
    this->turno=turno;
    this->cant_ins=ins;
    this->cupo=cupo;
}

DtClase::DtClase(int id, string nom, Turno turno){
    this->id=id;
    this->nombre=nom;
    this->turno=turno;
}

int DtClase::getId(){
    return id;
}

int DtClase::getCant_ins(){
    return cant_ins;
}

int DtClase::getCupo(){
    return cupo;
}

string DtClase::getNombre(){
    return nombre;
}

Turno DtClase::getTurno(){
    return turno;
}

DtClase::~DtClase(){
    //delete turno;
}

//ostream& operator<<(ostream& os, const DtClase& clase) {
//    os << "Id clase: "<<clase.id << "Nombre: " << clase.nombre << "Turno: " << clase.turno;
//    return os;
//}


