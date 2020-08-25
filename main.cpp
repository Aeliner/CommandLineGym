/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nuevo
 *
 * Created on 27 de marzo de 2018, 12:20 PM
 */



#include "Clase.h"
#include "Entrenamiento.h"
#include "Fecha.h"
#include "Inscripcion.h"
#include "Socio.h"
#include "Spinning.h"
#include "Turno.h"
#include "DtClase.h"
#include "DtEntrenamiento.h"
#include "DtSocio.h"
#include "DtSpinning.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

#define MAX_CLASES 50
#define MAX_SOCIOS 50
#define MAX_INSCRIPCIONES 50
/*ARRAYS*/
Clase** clases;
Socio** socios;
DtClase* res=NULL;
/*FUNCIONES*/
void agregarSocio(string ci, string nombre);
void agregarClase(DtClase& clase);
void agregarInscripcion(string ciSocio, int idClase, Fecha fecha);
void borrarInscripcion(string ciSocio, int idClase);
Fecha * generarFecha();
DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios);
DtClase& obtenerClase(int idClase);
bool ClasesVacia();



int main() {
    int opcion, subOpcion, cantBic, ID, turnito, cantSocios;
    
    
    bool enRambla;
    DtSocio** socio;
    DtClase** clase;
    DtSpinning** spinning;
    //DtClase* cl;
    DtEntrenamiento** entrenamiento;
    //DtClase& cla=**clase;
    string ci;
    string nombre;
    Turno turno;
    char xD;
    Inscripcion** ins;
    
    char op;
    //const char *lista[]={"Manana", "Tarde", "Noche"};
    
    
    clases = (Clase**) malloc (sizeof (Clase) * MAX_CLASES);
    socios = (Socio**) malloc (sizeof (Socio) * MAX_SOCIOS);
    
    for (int i = 0; i < MAX_CLASES; i++)
    {
        clases[i] = NULL;
    }
    
    for (int i = 0; i < MAX_SOCIOS; i++)
    {
        socios[i] = NULL;
    }
    
    do{
        system("cls");
        cout<<"----- Menu -----"<<endl;
        cout<<"1- Agregar socio"<<endl;
        cout<<"2- Agregar clase"<<endl;
        cout<<"3- Agregar inscripcion"<<endl;
        cout<<"4- Borrar inscripcion"<<endl;
        cout<<"5- Obtener info de socios"<<endl;
        cout<<"6- Obtener clase"<<endl;
        cout<<"0- Salir"<<endl<<endl;
        
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1:
                cout<<"--Agregar socio--"<<endl;
                cout<<"Ingrese ci: ";
                cin>>ci;
                cout<<endl;
                cin.ignore();
                cout<<"Ingrese nombre: ";
                //cin.getline(nombre,25,'\n');
                //cin>>nombre;
                getline(cin, nombre);
                try{
                   agregarSocio(ci, nombre); 
                } catch (const invalid_argument &e){
                    cout<<"Error : "<< e.what()<<endl;
                }
                system("pause");
                break;
                
            case 2:
                cout<<"--Tipo de clase---"<<endl;
                cout<<"1- Spinning"<<endl;
                cout<<"2- Entrenamiento"<<endl;
                cout<<"0- Salir"<<endl<<endl;
                cout<<"Elija una opcion: "<<endl<<endl;
                    cin>>subOpcion;
                if (subOpcion == 0)
                    break;
                
        cin.clear();
      	fflush(stdin);
                cout<<"Ingrese ID de la clase: ";
                cin>>ID;
                cout<<endl;
                cin.ignore();
                cout<<"Ingrese nombre de la clase: ";
                //cin>>nombre;
                getline(cin, nombre);
                cout<<endl;
                cout<<"Ingrese turno a elegir"<<endl;
                cout<<"0- Manana"<<endl;
                cout<<"1- Tarde"<<endl;
                cout<<"2- Noche"<<endl;
                cout<<"Opcion: ";
                cin>>turnito;
                switch(turnito){
                    case 0:
                        turno=Manana;
                        break;
                    case 1:
                        turno=Tarde;
                        break;
                    case 2:
                        turno=Noche;
                        break;
                }
               
                if (subOpcion == 1)
                {
                    cin.clear();
                    cout<<"---Clase de Spinning---"<<endl<<endl;
                    cout<<"Ingrese la cantidad de bicicletas: ";
                    cin>>cantBic;
                    try{
                    agregarClase(*(new DtSpinning(ID, nombre, turno, cantBic)));
                    }catch(const invalid_argument& e){
                    cout<<"Error: "<< e.what()<<endl;
                    system("pause");
                }
                    break;
                }
                if (subOpcion == 2)
                {
                    cin.clear();
                    cout<<"---Clase de Entrenamiento---"<<endl<<endl;
                   cout<<"La clase sera en la rambla? (s/n)";
                   cin>>op;
                   if (op=='s'){
                       enRambla=true;
                   }
                   if (op=='n'){
                       enRambla=false;
                   }
                     try{
                    agregarClase(*(new DtEntrenamiento(ID, nombre, turno, enRambla)));
                    }catch(const invalid_argument& e){
                    cout<<"Error: "<< e.what()<<endl;
                    system("pause");
                }
                    break;
                }
                break;
                case 3:
                    cout<<"---Agregar inscripcion---"<<endl<<endl;
                    cout<<"Ingrese la CI del socio"<<endl;
                    cin>>ci;
                    cout<<"Ingrese el ID de la clase"<<endl;
                    cin>>ID;
                    try{
                        agregarInscripcion(ci, ID, *generarFecha());
                    }catch(const invalid_argument& e){
                        cout<<"Error: "<< e.what()<<endl;
                    }
                    system("pause");
//                    for(int i = 0; i<MAX_INSCRIPCIONES; i++){
//                      cout<<ins[i]->getsocio()->getCi();
//                    }
                    break;
            case 4:
                cout<<"---Borrar inscripcion---"<<endl<<endl;
                cout<<"Ingrese la ci del socio"<<endl;
                cin>>ci;
                cout<<"Ingrese el ID de la clase"<<endl;
                cin>>ID;
                try{
                    borrarInscripcion(ci, ID); 
                }catch(const invalid_argument& e){
                    cout<<"Error: "<< e.what()<<endl;
                }
                system("pause");
                break;
            case 5:
                if (!ClasesVacia()){
                    cout<<"No hay clases cargadas aun"<<endl;
                    system("pause");
                }
                else{
                cout<<"--Obtener info de socios por clase--"<<endl<<endl;
                cout<<"Ingrese el id de la clase"<<endl;
                cin>>ID;

                    try{
                      socio = obtenerInfoSociosPorClase(ID, cantSocios);
                    } catch (const invalid_argument& e){
                        cout<<"Error: "<<e.what()<<endl;
                        system("pause");
                    }
                if (cantSocios>0)
                    for(int i = 0; i<cantSocios;i++){
                        cout<<"================================="<<endl;
                        cout<<"Cedula del socio: "<<endl<<socio[i]->getCI()<<endl;
                        cout<<"Nombre del socio: "<<endl<<socio[i]->getNombre()<<endl;
                        cout<<"Fecha de Inscripcion:"<<*(socio[i]->getFecha())<<endl;
                        }
                    system("pause");
                    
                    //Manejo memoria
                for(int i = 0; i<cantSocios;i++){
                    delete socio[i];
                    socio[i]=NULL;
                }
                
                }
                
                break;
                
            case 6:
                {
                cout<<"Queres ver informacion de la clase? Ingrese ID"<<endl;
                cin>>ID;
                try{
                *res=obtenerClase(ID);
                }catch(const invalid_argument &e){
                    cout<<"Error: "<<e.what()<<endl;
                    system("pause");
                    break;
                }
                
                DtSpinning* dtSp = dynamic_cast<DtSpinning*> (res);
        
                if (dtSp != NULL) {
                    cout<<*dtSp;

//                            cout<<"El ID es: "<<res->getId()<<endl;
//                            cout<<"El nombre es: "<<res->getNombre()<<endl;
//                            cout<<"El turno es: "<<lista[res->getTurno()]<<endl;
//                            cout<<"La cantidad de bicicletas es: "<<dtSp->getCantBicicletas()<<endl;
                            system("pause");
                            delete dtSp;
                            dtSp = NULL;
                                break;

                    } else {
                    DtEntrenamiento* dtEn = dynamic_cast<DtEntrenamiento*> (res);
                    cout<<*dtEn;
//                            cout<<"El ID es: "<<res->getId()<<endl;
//                            cout<<"El nombre es: "<<res->getNombre()<<endl;
//                            cout<<"El turno es: "<<lista[res->getTurno()]<<endl;
//                            cout<<"La clase es en la rambla: ";
//                            if(dtEn->getEnRambla()==true){
//                                cout<<"Si";
//                            } else {
//                                cout<<"No";
//                            }
                            system("pause");
                            delete dtEn;
                            dtEn = NULL;
                            break;
                    }
                }
            default:
            if (opcion!=0)
            {
                cout<<"Opcion Invalida"<<endl;
                system("pause");
                break;
            }    
        }
        }while(opcion != 0);
       return 0; 
    }
        
    


void agregarSocio(string ci, string nombre)
{
    int posicionLibre = 0;
    int ultimaPosLibre = 0;
    for (int i = 0; i < MAX_SOCIOS; i++)
    {
        if(socios[i] != NULL && socios[i]->getCi() == ci)
            throw invalid_argument ("Este socio ya existe");
        if (socios[i] == NULL)
        {
            posicionLibre++;
            ultimaPosLibre = i;
        }
    }
    
    if (posicionLibre == 0)
    {
        throw invalid_argument("No hay espacio libre para nuevos socios");
    }
    
    //Socio* nuevo = 
    
    socios[ultimaPosLibre] = new Socio(ci,nombre);
    
    cout<<"Se ha ingresado el socio satisfactoriamente"<<endl;
}

void agregarClase(DtClase& clase) {
    int posiciones_libres = 0;
    int posicion=0;
    
    for (int i = 0; i<MAX_CLASES; i++)
    if (clases[i] != NULL && clases[i]->getId() == clase.getId()) {
        //if (clases[i]->getId() == clase.getId()) {
            throw invalid_argument("Esa clase ya existe");
        //}
        } else {
        if (clases[i]==NULL){
            posiciones_libres++;
            posicion = i;
        }
    }
    
    if (posiciones_libres == 0)
    {
        throw invalid_argument("No hay espacio para clases");
    }     
    else 
    {
        DtSpinning* dtSp = dynamic_cast<DtSpinning*> (&clase);
        
        if (dtSp != NULL)
        {
            clases[posicion] = new Spinning(dtSp->getId(), dtSp->getNombre(), dtSp->getTurno(), dtSp->getCantBicicletas());
            delete dtSp;
            dtSp = NULL;
            cout<<"La clase de Spinning se ha agregado satisfactoriamente"<<endl<<endl;
        }             
        else 
        {
            DtEntrenamiento* dtEn = dynamic_cast<DtEntrenamiento*> (&clase);
            clases[posicion] = new Entrenamiento(dtEn->getId(), dtEn->getNombre(), dtEn->getTurno(), dtEn->getEnRambla());
            delete dtEn;
            dtEn = NULL;
            cout<<"La clase de Entrenamiento se ha agregado satisfactoriamente"<<endl<<endl;
        }
    }
    
    system("pause");
}
 
Fecha * generarFecha(){
    Fecha * nombresito = NULL;
    bool fechaInvalida = false;
    int dia, anio, mes;
    
    do
    {
        fechaInvalida = false;
        cout<<"Ingrese el dia"<<endl;
        cin>>dia;
        cout<<"Ingrese el mes"<<endl;
        cin>>mes;
        cout<<"Ingrese el anio"<<endl;
        cin>>anio;
        
        try{
            nombresito = new Fecha (dia, mes, anio);
        }catch (const invalid_argument& e) {
            cout<<"Error: "<< e.what()<<endl;
            fechaInvalida = true;
        }
    }while(fechaInvalida);
    return nombresito;
}

void agregarInscripcion(string ci, int id, Fecha fecha){
    Socio* socios2 = NULL;
    Clase* clase2 = NULL;
    
    for(int i = 0; i < MAX_SOCIOS; i++)
    {
        if (socios[i] != NULL && socios[i]->getCi() == ci)
        {
            socios2 = socios[i];
            break;
        }
    }
    
    if (socios2 == NULL)
    {
        throw invalid_argument ("Este socio no existe");
    }
    
    for(int i = 0; i < MAX_CLASES; i++)
    {
        if(clases[i] != NULL && clases[i]->getId()== id)
        {
            clase2 = clases[i];
            break;
        }
    }
    
    if (clase2 == NULL)
    {
        throw invalid_argument ("Esta clase no existe");
    }
    
    if (clase2->CantInscripciones()==clase2->Cupo()){
        throw invalid_argument ("Esta clase no tiene cupos disponibles");
    }
    
    clase2->addInscripcion(socios2,new Fecha(fecha.getDia(), fecha.getMes(), fecha.getAnio()),MAX_INSCRIPCIONES,ci);
    
//    Inscripcion** inscrip = clase2->getInscripciones();
//    
//    for(int i = 0; i < MAX_INSCRIPCIONES; i++)
//    {
//        if (inscrip[i] != NULL && inscrip[i]->getsocio()->getCi() == ci)
//        {
//            throw invalid_argument("Esta inscripcion ya existe");
//        }
//    }
//    
//   clase2->addInscripcion(new Inscripcion(new Fecha(fecha.getDia(), fecha.getMes(), fecha.getAnio()), socios2));
   cout<<"La inscripcion del socio se ha completado satisfactoriamente"<<endl;
   
}

void borrarInscripcion(string ci, int id)
{
    Socio* socios2=NULL;
    Clase* clase2=NULL;
    
    for(int i = 0; i < MAX_SOCIOS; i++)
    {
        if (socios[i] != NULL && socios[i]->getCi() == ci)
        {
            socios2 = socios[i];
            break;
        }
    }
    
    if (socios2 == NULL)
    {
        throw invalid_argument ("Este socio no existe");
    }
    
    for(int i = 0; i < MAX_CLASES; i++)
    {
        if(clases[i] != NULL && clases[i]->getId()== id)
        {
            clase2 = clases[i];
            break;
        }
    }
    
    if (clase2 == NULL)
    {
        throw invalid_argument ("Esta clase no existe");
    }
    
    clase2->borrarInsc(MAX_INSCRIPCIONES, ci);
    
//    Inscripcion** inscrip = clase2->getInscripciones();
//    bool control = false;
//    
//    for(int i = 0; i < MAX_INSCRIPCIONES; i++)
//    {
//        if (inscrip[i] != NULL && inscrip[i]->getsocio()->getCi() == ci)
//        {
//            delete inscrip[i];
//            inscrip[i]=NULL;
//            control = true;
//           cout<<"La inscripcion se ha borrado satisfactoriamente"<<endl<<endl;
//            break;
//        }
//    }
//    if (!control)
//        throw invalid_argument ("Esta inscripcion no existe");
   
    
}

DtSocio** obtenerInfoSociosPorClase(int id, int &cantSocios) {
    Clase* clase = NULL;
    cantSocios=0;
    int posicion =0;
    for (int i = 0; i < MAX_CLASES; i++) {
        if (clases[i] != NULL && clases[i]->getId() == id){
            clase = clases[i];
            break;
        }
    }
    if (clase == NULL) {
        throw invalid_argument("Esta clase no existe");
    }

//    Inscripcion** inscripciones = clase->getInscripciones();
//
//    for (int i = 0; i < MAX_INSCRIPCIONES; i++) {
//        if (inscripciones[i] != NULL) {
//            cantSocios++;
//        }
//    }
//    if (cantSocios==0){
//        throw invalid_argument("Esta clase no tiene inscripciones");
//    }
//    DtSocio** soc = (DtSocio**) malloc(sizeof (DtSocio) * cantSocios);
//
//    for (int i = 0; i < MAX_INSCRIPCIONES; i++) {
//        if (inscripciones[i] != NULL) {
//            soc[posicion] = new DtSocio(inscripciones[i]->getsocio()->getCi(), inscripciones[i]->getsocio()->getNombre(), inscripciones[i]->getfecha());
//            posicion++;
//        }
//        
//    }
//    return soc;
    
    DtSocio** soc=clase->obtenerInfo(cantSocios, MAX_INSCRIPCIONES);
    return soc;

    
}

DtClase& obtenerClase(int idClase){
    Clase* cla = NULL; 
    //DtClase* res;
    //DtClase& resul=*res;
    for (int i=0; i<MAX_CLASES; i++){
        if(clases[i] != NULL && clases[i]->getId() == idClase){
            cla = clases[i];
        }
        //break;
    }

    if(cla==NULL){
        throw invalid_argument ("Esta clase no existe");
    } 
    
    Spinning* sp = dynamic_cast<Spinning*> (cla);
            if (sp != NULL){
                res=new DtSpinning (sp->getId(), sp->getNombre(), sp->getTurno(), sp->getCantBicicletas(), sp->CantInscripciones());
                //resul=*res;
                        
            } else {
                Entrenamiento* en = dynamic_cast<Entrenamiento*>(cla);
                res=new DtEntrenamiento (en->getId(), en->getNombre(), en->getTurno(), en->getRambla(), en->Cupo(),en->CantInscripciones());
                //resul=*res;
            }
        return *res;
        }

bool ClasesVacia(){
    bool x = false;
    for (int i=0;i<MAX_CLASES;i++){
        if (clases[i]!=NULL)
            x = true;   }
    return x;
}

    





