/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSocio.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:23 PM
 */

#ifndef DTSOCIO_H
#define DTSOCIO_H
#include<iostream>
#include <string>
#include "Fecha.h"

using namespace std;
class DtSocio {
private:
    string CI;
    string nombre;
    Fecha* fecha;
    
public:
    DtSocio(string, string, Fecha*);
    
    string getCI();
    string getNombre();
    Fecha* getFecha();
    
    ~DtSocio();

};



#endif /* DTSOCIO_H */

