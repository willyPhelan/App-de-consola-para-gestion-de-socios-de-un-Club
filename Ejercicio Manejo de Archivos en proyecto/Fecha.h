#pragma once
#include <iostream>

using namespace std ;

class Fecha {

    private:

        int dia, mes, anio ;

    public:

        Fecha(int _dia=0, int _mes=0, int _anio=0) ;

        void cargar() ;
        bool esCorrecta() ;
        void mostrar() ;

        void setDia(int d) ;
        void setMes(int m) ;
        void setAnio(int a) ;

        int getDia() ;
        int getMes() ;
        int getAnio() ;
    };


