/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSpinning.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:40 PM
 */

#include "DtSpinning.h"

DtSpinning::DtSpinning(int id, string nombre,Turno turno,int cantBicicletas, int ins):
DtClase(id, nombre, turno, cantBicicletas, ins){
    this->cantBicicletas=cantBicicletas;
}

DtSpinning::DtSpinning(int id, string nombre,Turno turno,int cantBicicletas):
DtClase(id, nombre, turno){
    this->cantBicicletas=cantBicicletas;
}

int DtSpinning::getCantBicicletas(){
    return cantBicicletas;
}

DtSpinning::~DtSpinning(){
    
}

ostream& operator<<(ostream& os, const DtSpinning& dte) {
    //os << dte.id << "/" << dte.nombre << "/" << dte.turno << "/" << dte.enRambla;
    os<<"El ID es: "<<dte.id<<endl;
    os<<"El nombre es: "<<dte.nombre<<endl;
    os<<"El turno es: ";
    if (dte.turno==0)
        os<<"Manana"<<endl;
    if (dte.turno==1)
        os<<"Tarde"<<endl;
    if (dte.turno==2)
        os<<"Noche"<<endl;
    os<<"Cantidad de Bicicletas: ";
    os<<dte.cantBicicletas<<endl;
    os<<"El cupo de esta clase es "<<dte.cupo<<" y la cantidad de inscriptos es "<<dte.cant_ins<<endl;
    return os;
}

