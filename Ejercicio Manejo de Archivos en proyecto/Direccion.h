#pragma once
#include <iostream>

using namespace std ;

class Direccion {

    private:

        int numero ;
        char calle[30], localidad[30] ;

    public:

        void cargar() ;
        void mostrar() ;
    } ;

