/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spinning.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:34 PM
 */

#include "Spinning.h"

Spinning::Spinning(int id, string nombre, Turno turno, int cantBicicletas) : 
Clase(id, nombre, turno){
 this->cantBicicletas=cantBicicletas;   
}

int Spinning::getCantBicicletas(){
    return cantBicicletas;
}

 int Spinning::Cupo(){
    return cantBicicletas;
}

void Spinning::setCantBicicletas(int cant){
    this->cantBicicletas=cant;
}

Spinning::~Spinning(){
}


