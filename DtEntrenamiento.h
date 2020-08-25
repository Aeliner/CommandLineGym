/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtEntrenamiento.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:38 PM
 */

#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H

#include<iostream>
#include <string>
#include "Turno.h"
#include "DtClase.h"

using namespace std;

class DtEntrenamiento: public DtClase {
private:
    bool enRambla;
public:
    DtEntrenamiento(int, string, Turno, bool, int, int);
    DtEntrenamiento(int, string, Turno, bool);
    DtEntrenamiento();
    
    bool getEnRambla();
    friend ostream& operator<<(ostream&, const DtEntrenamiento&);
    
    ~DtEntrenamiento();
};


#endif /* DTENTRENAMIENTO_H */

