/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Socio.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:21 PM
 */

#include "Socio.h"

Socio::Socio(string ci, string nom){
    this->nombre=nom;
    this->ci=ci;
}

string Socio::getCi(){
    return ci;
}

string Socio::getNombre(){
    return nombre;
}
void Socio::setCi(string id){
    this->ci=id;
}

void Socio::setNombre(string nom){
    this->nombre=nom;
}

Socio::~Socio(){
}

