#pragma once
#include "Socio.h"

// Prototipos de funciones globales

bool escribirRegistroSocio(Socio reg) ;
bool mostrarRegistroSocio() ;
bool mostrarRegistroPorDNI(int dni) ;
bool agregarRegistroSocio() ;
int buscarRegistroSocio(int idSocio) ;
int contarRegistrosSocios() ;
int contarRegistrosSocios2() ;
void buscarSocioPorId() ;
Socio leerRegistroSocio(int posReg) ;
Socio leerRegistroSocio2(int posReg) ;
bool existeDNI(int dni) ;
void menu() ;


