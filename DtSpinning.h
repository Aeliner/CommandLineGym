/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSpinning.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:40 PM
 */

#ifndef DTSPINNING_H
#define DTSPINNING_H

#include<iostream>
#include <string>
#include "Turno.h"
#include "DtClase.h"

using namespace std;

class DtSpinning: public DtClase{
private:
    int cantBicicletas;
public:
    DtSpinning(int, string, Turno, int, int);
    DtSpinning(int, string, Turno, int);
    
    int getCantBicicletas();
    friend ostream& operator<<(ostream&, const DtSpinning& );
    
    ~DtSpinning();
};


#endif /* DTSPINNING_H */

