/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSocio.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:23 PM
 */

#include "DtSocio.h"

DtSocio::DtSocio(string CI, string nombre, Fecha* date){
    this->CI=CI;
    this->nombre=nombre;
    this->fecha=date;
}

string DtSocio::getCI(){
    return CI;
}

string DtSocio::getNombre(){
    return nombre;
}
Fecha* DtSocio::getFecha(){
    return fecha;
}

DtSocio::~DtSocio(){
    delete fecha;
}

