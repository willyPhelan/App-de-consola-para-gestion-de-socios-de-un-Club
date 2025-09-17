#pragma once
#include <iostream>
#include "Fecha.h"
#include "Direccion.h"

using namespace std;

class Socio {

private:

    int dni, idSocio ;
    char nombre[30], apellido[30], telefo[15], email[40] ;
    bool estado ; // true = activo, false = dado de baja

    Fecha fechaNacimiento ;
    Direccion domicilio ;




public:

    Socio() ;

    void cargar() ;
    void mostrar() ;

    int getIdSocio() ;
    Fecha getFechaNacimiento() ;
    Direccion getDomicilio() ;
    int getDNI() ;

    bool getEstado() ;  // getter para borrado

    void setIdSocio(int id) ;
    void setDNI(int nuevoDni) ;
    void setFechaNacimiento(Fecha nac) ;
    void setDomicilio(Direccion dom) ;
    void setDiaNacimiento(int d) ;

    void setEstado(bool estado) ; // para borrado logico


} ;


