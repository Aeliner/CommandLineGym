/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spinning.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:34 PM
 */

#ifndef SPINNING_H
#define SPINNING_H
#include<iostream>
#include <string>
#include "Clase.h"

using namespace std;

class Spinning: public Clase {
private:
    int cantBicicletas;
public:
    Spinning(int, string, Turno, int);
    
    int getCantBicicletas();
    void setCantBicicletas(int);
    int Cupo();
    ~Spinning();
};

#endif /* SPINNING_H */

