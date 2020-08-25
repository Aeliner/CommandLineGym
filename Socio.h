/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Socio.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:21 PM
 */

#ifndef SOCIO_H
#define SOCIO_H

#include<iostream>
#include <string>

using namespace std;

class Socio {
private:
    string ci;
    string nombre;
   
public:
    Socio();
    Socio(string, string);
    
    string getCi();
    string getNombre();
    
    void setCi(string);
    void setNombre(string);
    
    ~Socio();

};

#endif /* SOCIO_H */

