/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:29 PM
 */

#ifndef CLASE_H
#define CLASE_H
#include<iostream>
#include <string>
#include "Inscripcion.h"
#include "Fecha.h"
#include "Turno.h"
#include "DtSocio.h"

using namespace std;

class Clase {
private:
    int id;
    string nombre;
    Turno turno;
    Inscripcion* inscripciones[50];
public:
    Clase(int, string, Turno);
    Clase();
    
    int getId();
    string getNombre();
    Turno getTurno();
    Inscripcion** getInscripciones();
    
    void setId(int);
    void setNombre(string);
    void setTurno(Turno);
    void addInscripcion(Socio*, Fecha*, int, string);
    void borrarInsc(int, string);
    DtSocio** obtenerInfo(int&, int);
    int CantInscripciones();
    
    virtual int Cupo () = 0;
    virtual ~Clase();


};

#endif /* CLASE_H */

