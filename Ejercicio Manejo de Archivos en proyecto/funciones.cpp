#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"

using namespace std ;

bool escribirRegistroSocio(Socio reg) {

    FILE* pSocio = fopen("socios.dat", "ab") ;

    if (pSocio == nullptr) return false ;

    bool escribio = fwrite(&reg, sizeof(Socio), 1, pSocio) ;

    fclose(pSocio) ;

    return escribio ;
}

bool mostrarRegistroSocio() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        reg.mostrar() ;

        cout << "------------------------\n" ;
    }

    fclose(pSocio) ;

    return true ;
}

bool mostrarRegistroPorDNI(int dni) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    bool encontrado = false ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getDNI() == dni) {

            cout << "\nSocio encontrado:\n" ;

            reg.mostrar() ;

            encontrado = true ;

            break ;
        }
    }

    fclose(pSocio) ;

    if (!encontrado) cout << "No existe socio con ese DNI\n" ;

    return encontrado ;
}

bool agregarRegistroSocio() {

    Socio nuevoSocio ;

    nuevoSocio.cargar() ;

    int id = nuevoSocio.getIdSocio() ;

    int dni = nuevoSocio.getDNI() ;

    int posReg = buscarRegistroSocio(id) ;

    bool dniExiste = existeDNI(dni) ;

    if (posReg != -1 || dniExiste) {

        cout << "\nNo se puede repetir el ID ni el DNI.\n" ;

        return false ;
    }

    return escribirRegistroSocio(nuevoSocio) ;
}

int buscarRegistroSocio(int idSocio) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return -1 ;

    Socio reg ;

    int pos = 0 ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getIdSocio() == idSocio) {

            fclose(pSocio) ;

            return pos ;
        }
        pos++ ;
    }
    fclose(pSocio) ;

    return -1 ;
}

int contarRegistrosSocios() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return 0 ;

    Socio reg ;
    int contador = 0 ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        contador++ ;
    }
    fclose(pSocio) ;

    return contador ;
}

int contarRegistrosSocios2() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return -1 ;

    fseek(pSocio, 0, SEEK_END) ;

    int cantBytes = ftell(pSocio) ;

    fclose(pSocio) ;

    return cantBytes / sizeof(Socio) ;
}

void buscarSocioPorId() {

    int idSocio;

    cout << "Ingrese el ID del socio que desea buscar: " ;
    cin >> idSocio ;

    int pos = buscarRegistroSocio(idSocio) ;

    if (pos == -1) {

        cout << "No existe socio con ese ID\n" ;

        return ;
    }

    Socio reg = leerRegistroSocio(pos) ;

    cout << "\nSocio encontrado:\n" ;

    reg.mostrar() ;
}

Socio leerRegistroSocio(int posReg) {

    Socio reg ;

    reg.setIdSocio(-1) ;

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return reg ;

    int pos = 0 ;
    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (pos == posReg) {

            fclose(pSocio) ;

            return reg;

        }

        pos++ ;
    }

    fclose(pSocio) ;

    reg.setIdSocio(-1) ;

    return reg ;
}

Socio leerRegistroSocio2(int posReg) {

    Socio reg ;

    reg.setIdSocio(-1) ;

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return reg ;

    fseek(pSocio, posReg * sizeof(Socio), SEEK_SET) ;

    fread(&reg, sizeof(Socio), 1, pSocio) ;

    fclose(pSocio) ;

    return reg;
}

bool existeDNI(int dni) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getDNI() == dni) {

            fclose(pSocio) ;

            return true ;
        }
    }

    fclose(pSocio) ;

    return false ;
}


// FUNCION PARA MODIFICAR UN REGISTRO

bool modificarRegistroSocio() {

    int idSocio ;

    cout << "Ingrese el ID del socio a modificar: " ;

    cin >> idSocio ;

    int pos = buscarRegistroSocio(idSocio) ; // busco socio por ID

    if (pos == -1) {

        cout << "No existe socio con ese ID.\n" ;

        return false ;
    }

    // Mostrar el socio actual

    cout << "\n Socio actual: \n" ;

    Socio actual = leerRegistroSocio(pos) ; // leo el contenido del registro

    actual.mostrar() ;

    // Crear un socio nuevo con los datos actualizados

    Socio nuevo ;

    cout << "\nIngrese los nuevos datos del socio:\n" ;

    nuevo.cargar();   // asumimos que tu clase Socio tiene método cargar()

    // Validar ID y DNI

    if (nuevo.getIdSocio() != idSocio && buscarRegistroSocio(nuevo.getIdSocio()) != -1) {

        cout << endl << "Error: El ID ya esta en uso por otro socio. \n" ;

        system("pause") ;

        return false ;
    }

    if (nuevo.getDNI() != actual.getDNI() && existeDNI(nuevo.getDNI())) {

        cout << endl << "Error: El DNI ya esta en uso por otro socio. \n" ;

        system("pause") ;

        return false ;
    }



    // Sobrescribir en el archivo

    FILE* pSocio = fopen("socios.dat", "rb+") ; // "rb" es el parametro que se usa para modificar

    if (pSocio == nullptr) return false ;

    fseek(pSocio, pos * sizeof(Socio), SEEK_SET) ; // posciciono el puntero

    bool escribio = fwrite(&nuevo, sizeof(Socio), 1, pSocio) ; // escribo en la posicion del registro a modificar

    fclose(pSocio) ;

    if (escribio) {

        cout << "\n Registro modificado correctamente.\n" ;

         system("pause") ;

        return true ;

    } else {

        cout << "\n Error al modificar el registro.\n" ;

        return false ;
    }
}

// FUNCION QUE MODIFICA UNICAMENTE EL DNI


bool modificarDniSocio() {

    int idSocio ;

    cout << "Ingrese el ID del socio cuyo DNI desea modificar: " ;

    cin >> idSocio ;

    int pos = buscarRegistroSocio(idSocio) ; // busco el registro en el archivo por el ID

    if (pos == -1) {

        cout << "No existe socio con ese ID. \n" ;

        return false ;
    }

    Socio socioActual = leerRegistroSocio(pos) ; // leo el registro completo

    cout << endl << "Socio actual: \n" ;

    socioActual.mostrar() ;

    int nuevoDni ;

    cout << "Ingrese el nuevo DNI: " ;

    cin >> nuevoDni ;

    // Valido que no exista ya ese DNI en otro socio

    if (nuevoDni != socioActual.getDNI() && existeDNI(nuevoDni)) { // (nuevoDni != socioActual.getDNI() verifica si el nuevo dni ingresado es igual al dni que ya se encuentra en el registro // existeDNI(nuevoDni) busca que no haya otro registro con el mismo dni en el archivo, devuelve true si ya existe otro socio con ese mismo DNI.

        cout << "\n Error: El DNI ya está en uso por otro socio. \n" ;

        return false ;
    }

    // Actualizar solo el DNI

    socioActual.setDNI(nuevoDni) ;

    FILE* pSocio = fopen("socios.dat", "rb+") ; // "rb" para modificaciones

    if (pSocio == nullptr) return false ;

    fseek(pSocio, pos * sizeof(Socio), SEEK_SET) ; // posiciono el puntero en la poscicion del registro a modificar

    bool escribio = fwrite(&socioActual, sizeof(Socio), 1, pSocio) ; // escribo sobre el archivo // fwrite(puntero, tamaño, cantidad, archivo)

    fclose(pSocio) ;

    if (escribio) {

        cout << "DNI modificado correctamente. \n" ;

        return true ;

    } else {

        cout << "Error al modificar el DNI. \n" ;

        return false ;
    }
}


// BAJA LOGICA //

bool bajaLogicaSocio(int idSocio) {

    int pos = buscarRegistroSocio(idSocio) ;

    if (pos == -1) {

        cout << "No existe socio con ese ID. \n" ;

        return false ;
    }

    Socio socio = leerRegistroSocio(pos) ;

    if (!socio.getEstado()) {

        cout << "El socio ya esta dado de baja.\n" ;

        return false ;
    }

    socio.setEstado(false); // Si no estaba dado de baja, marcar como dado de baja

    FILE* pSocio = fopen("socios.dat", "rb+") ; // modifico el registro con rb

    if (pSocio == nullptr) return false ;

    fseek(pSocio, pos * sizeof(Socio), SEEK_SET) ; // posiciono puntero

    bool escribio = fwrite(&socio, sizeof(Socio), 1, pSocio) ;

    fclose(pSocio) ;

    if (escribio) {

        cout << "Socio dado de baja correctamente. \n" ;

        return true ;

    } else {

        cout << "Error al dar de baja al socio.\n" ;

        return false ;
    }
}

bool mostrarRegistrosActivos() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    bool hayActivos = false ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getEstado()) {   // <-- Solo mostrar si está activo

            reg.mostrar() ;

            cout << "------------------------\n" ;

            hayActivos = true ;
        }
    }

    fclose(pSocio) ;

    if (!hayActivos) {

        cout << "No hay socios activos cargados. \n" ;
    }

    return hayActivos ;
}


void menu() {

    int opcion ;

    do {
        system("cls") ;

        cout << "=== MENU SOCIOS === \n" ;
        cout << "1. Agregar registro \n" ;
        cout << "2. Buscar registro por DNI \n" ;
        cout << "3. Buscar registro por ID de socio \n" ;
        cout << "4. Listar todos los registros \n" ;
        cout << "5. Contar todos los registros \n" ;
        cout << "6. Modificar socio \n" ;
        cout << "7. Modificar DNI de socio \n" ;
        cout << "8. Dar de baja un socio \n" ;
        cout << "9. Mostrar todos los socios activos \n" ;
        cout << "0. Salir \n" ;

        cout << endl <<"Ingrese opcion: " ;

        cin >> opcion ;

        switch (opcion) {

        case 1:

            system("cls") ;

            cout << "--- AGREGAR REGISTRO ---\n" << endl ;

            if (agregarRegistroSocio())

                cout << "Registro agregado correctamente.\n" ;

            else
                cout << "No se pudo agregar el registro.\n" ;

            system("pause") ;

            break ;

        case 2 :

            system("cls") ;

            cout << "--- MOSTRAR REGISTRO POR DNI ---\n" ;
            int dniBuscar ;

            cout << "Ingrese DNI a buscar: " ;
            cin >> dniBuscar ;

            mostrarRegistroPorDNI(dniBuscar) ;

            system("pause") ;

            break ;

        case 3:

            system("cls") ;

            cout << "--- BUSCAR SOCIO POR ID ---\n" ;

            buscarSocioPorId() ;

            system("pause") ;

            break ;

        case 4:

            system("cls") ;

            cout << "--- LISTADO DE TODOS LOS SOCIOS ---\n" << endl ;

            if (!mostrarRegistroSocio())

                cout << "No hay registros cargados.\n" ;

            system("pause") ;

            break ;

        case 5:

            system("cls") ;

            cout << "CANTIDAD DE SOCIOS: " << contarRegistrosSocios2() << endl ;

            system("pause") ;

            break ;

        case 6:

            system("cls") ;

            modificarRegistroSocio() ;

            system("pause") ;

            break ;

        case 7:

            system("cls") ;

            modificarDniSocio() ;

            system("pause") ;

            break ;

        case 8:

            system("cls") ;

            int idBaja ;

            cout << "Ingrese el ID del socio a dar de baja: " ;

            cin >> idBaja ;

            bajaLogicaSocio(idBaja) ;

            system("pause") ;

            break ;

        case 9:

            system("cls") ;

            cout << "--- LISTADO DE SOCIOS ACTIVOS ---\n" << endl ;

            mostrarRegistrosActivos() ;

            system("pause") ;

            break ;



        case 0:

            cout << "Saliendo...\n" ;

            break ;

        default:

            cout << "Opcion invalida.\n" ;

            system("pause") ;

            break ;
        }

    } while (opcion != 0) ;
}




