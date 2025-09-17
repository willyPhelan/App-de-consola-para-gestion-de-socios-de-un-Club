#include "Socio.h"

Socio::Socio() {
    idSocio = 0;
    dni = 0;
    nombre[0] = '\0' ;
    apellido[0] = '\0' ;
    estado = true ; // por defecto activo
}

void Socio::cargar() {

    cout << "Id socio: " << endl ;
    cin >> idSocio ;

    cout << "DNI: " << endl ;
    cin >> dni ;

    cout << "Nombre: " << endl ;
    cin >> nombre ;

    cout << "Apellido: " << endl ;
    cin >> apellido ;

    cout << endl << "Fecha de nacimiento: " << endl ;
    fechaNacimiento.cargar() ;

    cout << endl << "Domicilio: " << endl ;
    domicilio.cargar() ;
}

void Socio::mostrar() {

    cout << "Id de Socio: " << idSocio << endl ;

    cout << "Nombre: " << nombre << endl ;

    cout << "Apellido: " << apellido << endl ;

    cout << "DNI: " << dni << endl ;

    cout << "Fecha de nacimiento: " << endl ;

    fechaNacimiento.mostrar() ;

    cout << endl << "Domicilio" << endl ;

    domicilio.mostrar() ;

    cout << endl ;

}


int Socio::getIdSocio() { return idSocio ; }

Fecha Socio::getFechaNacimiento() { return fechaNacimiento ; }

Direccion Socio::getDomicilio() { return domicilio ; }

int Socio::getDNI() { return dni ; }

void Socio::setIdSocio(int id) { idSocio = id ; }

void Socio::setDNI(int nuevoDni) { dni = nuevoDni ; }

void Socio::setFechaNacimiento(Fecha nac) { fechaNacimiento = nac ; }

void Socio::setDomicilio(Direccion dom) { domicilio = dom ; }

void Socio::setDiaNacimiento(int d) { fechaNacimiento.setDia(d) ; }

// PARA BORRADO

void Socio::setEstado(bool _estado) { estado = _estado ; }

bool Socio::getEstado() { return estado ; }
