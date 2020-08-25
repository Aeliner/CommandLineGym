/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.h
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:26 PM
 */

#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int, int, int);

    int getDia();
    int getMes();
    int getAnio();
    friend ostream& operator<<(ostream&, const Fecha&);

    ~Fecha();

};

#endif /* FECHA_H */

