/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtEntrenamiento.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:38 PM
 */

#include "DtEntrenamiento.h"
//const char *lista[]={"Manana", "Tarde", "Noche"};
//const char *rambla[]={"No", "Si"};

DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla, int cupo, int ins):
DtClase(id, nombre, turno, cupo, ins){
    this->enRambla=enRambla;
}

DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla):
DtClase(id, nombre, turno){
    this->enRambla=enRambla;
}

bool DtEntrenamiento::getEnRambla(){
    return enRambla;
}

DtEntrenamiento::~DtEntrenamiento(){
    
}


ostream& operator<<(ostream& os, const DtEntrenamiento& dte) {
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
    os<<"La clase es en la rambla: ";
    if(dte.enRambla==true){
        os<<"Si"<<endl;
    } else {
        os<<"No"<<endl;
    }
    os<<"El cupo de esta clase es "<<dte.cupo<<" y la cantidad de inscriptos es "<<dte.cant_ins<<endl;
    
    return os;
}


