/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrenamiento.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:32 PM
 */

#include "Entrenamiento.h"

Entrenamiento::Entrenamiento(int id, string nombre, Turno turno, bool enRambla) : 
Clase(id, nombre, turno) {
   this->enRambla = enRambla;
}

bool Entrenamiento::getRambla(){
    return enRambla;
}

 int Entrenamiento::Cupo(){
    if(enRambla==false){
        return 10;
    }
    else return 20;
} 

void Entrenamiento::setRambla(bool Rambla){
    this->enRambla=Rambla;
}

Entrenamiento::~Entrenamiento(){
}


