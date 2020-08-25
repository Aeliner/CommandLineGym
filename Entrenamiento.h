/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrenamiento.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:32 PM
 */

#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include<iostream>
#include <string>
#include "Clase.h"

using namespace std;

class Entrenamiento: public Clase {
private:
    bool enRambla;
public:
    Entrenamiento(int, string, Turno, bool);
    
    bool getRambla();
    void setRambla(bool);
    int Cupo();
    ~Entrenamiento();

};


#endif /* ENTRENAMIENTO_H */

