#include "Fecha.h"

Fecha::Fecha(int _dia, int _mes, int _anio) {

    dia = _dia ;
    mes = _mes ;
    anio = _anio ;
}

void Fecha::cargar() {

    cout << "Dia: " ;
    cin >> dia ;

    cout << "Mes: " ;
    cin >> mes ;

    cout << "Anio: " ;
    cin >> anio ;
}

bool Fecha::esCorrecta() {

    return (dia != -1 && mes != -1 && anio != -1) ;
}

void Fecha::mostrar() {

    if(esCorrecta()) cout << dia << "/" << mes << "/" << anio ;

    else cout << "Fecha incorrecta" << endl ;
}

void Fecha::setDia(int d) {

    if(d >= 1 && d <= 31) dia = d ;

    else dia = -1 ;
}

void Fecha::setMes(int m) {

    if(m >= 1 && m <= 12) mes = m ;

    else mes = -1 ;
}

void Fecha::setAnio(int a) {

    if(a > 0) anio = a ;

    else anio = -1 ;
}

int Fecha::getDia() { return dia ; }
int Fecha::getMes() { return mes ; }
int Fecha::getAnio() { return anio ; }
