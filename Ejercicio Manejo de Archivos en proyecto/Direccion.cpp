#include "Direccion.h"

void Direccion::cargar() {

    cout << "Ingrese la calle: " << endl ;
    cin >> calle ;

    cout << "Ingrese el numero: " << endl ;
    cin >> numero ;

    cout << "Ingrese la localidad: " << endl ;
    cin >> localidad ;
}

void Direccion::mostrar() {

    cout << "Calle: " << calle << endl ;
    cout << "Numero: " << numero << endl ;
    cout << "Localidad: " << localidad << endl ;
}
