/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inscripcion.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:24 PM
 */

#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "Socio.h"
#include "Fecha.h"
#include<iostream>
#include <string>

using namespace std;

class Inscripcion {
private:
    Fecha* fecha;
    Socio* socio;
public:
    Inscripcion(Fecha*,Socio*);
    Inscripcion();
    Fecha* getfecha();
    Socio* getsocio();
    
    void setSocio(Socio*);
    void setFecha(Fecha*);
    
    ~Inscripcion();
};

#endif /* INSCRIPCION_H */

