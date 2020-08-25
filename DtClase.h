/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtClase.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:37 PM
 */

#ifndef DTCLASE_H
#define DTCLASE_H

#include<iostream>
#include <string>
#include "Turno.h"

using namespace std;

class DtClase {
protected:
    int id;
    string nombre;
    Turno turno;
    int cupo;
    int cant_ins;
public:
    DtClase(int, string, Turno);
    DtClase(int, string, Turno, int, int);
    DtClase();
    
    virtual int getId();
    virtual string getNombre();
    virtual Turno getTurno();
    virtual int getCupo();
    virtual int getCant_ins();
    friend ostream& operator<<(ostream&, const DtClase&);
    
    virtual ~DtClase();

};

#endif /* DTCLASE_H */

