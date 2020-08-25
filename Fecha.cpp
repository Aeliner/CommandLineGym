/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.cpp
 * Author: Nuevo
 * 
 * Created on 27 de marzo de 2018, 12:26 PM
 */

#include "Fecha.h"

#include <stdexcept>

Fecha::Fecha(int dia, int mes, int anio) {
    if (dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1900) {
        throw std::invalid_argument("Fecha Invalida");
    }

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}

Fecha::~Fecha() {
}

ostream& operator<<(ostream& os, const Fecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
}
