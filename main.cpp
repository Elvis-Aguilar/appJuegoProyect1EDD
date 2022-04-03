#include <iostream>
#include "object/Jugador.h"
#include "juego/Juego.h"
#include "archivos/Archivos.h"


using  namespace std;

void menuOpciones();
void pedirDatosJugador();
Jugador *jugadorDir;
int niveles;
int filas;
int columnas;
Juego *juegoDir;
Archivos *archivos = new Archivos();



int main() {
    cout << "BIENBENIDO! Nueva Version del Juego del 15 " <<endl;
    menuOpciones();
    return 0;
}

/**
 * menu principal de opciones
 */
void menuOpciones(){
    int opcionGeneral=0;
    do {
        cout << "-----Opciones Generales!!-------- " <<endl;
        cout << "1.- Iniciar Juego " <<endl;
        cout << "2.- Ver Puntajes Registrados (Reportes)" <<endl;
        cout << "3.- Salir" <<endl;
        cout << "Digite la opcion que decee" <<endl;
        cin >> opcionGeneral;
        switch (opcionGeneral) {
            case 1:
                cout << "-----Exelente!! COMIENZA A JUEGAR-------- " <<endl<<endl;
                pedirDatosJugador();
                break;
            case 2:
                cout << "-----Los Puntajes Son los siguentes!-------- " <<endl;
                archivos->leecturaArchivo();
                break;
            case 3:
                cout << "------No Olvides que eres un Campeon------- " <<endl;
                break;
            default:
                delete archivos;
                cout << "-----No manches! Digita una Opcion Valida-------- " <<endl;
                break;
        }
    } while (opcionGeneral != 3);
}

/**
 * logica del juego en pedir datos y seguir con el juego
 */
void pedirDatosJugador(){
    cout << "Igrese su nombre:  ";
    char nombre[30];
    //cin.getline(nombre,30);
    cin >> nombre;
    char *dir ;
    dir = nombre;
    Jugador jugador(0, dir,0);
    jugadorDir = &jugador;
    cout << "" <<endl;
    cout << "Hay que comenzar el Juego-- "<<jugadorDir->getNombre()<<endl<<endl;
    cout << "Opciones de Inicio de Juego "<<endl;
    int opcion=0;
    while (opcion ==0){
        cout << "1.- Crear el tablero por medio de un Archivo de Entrada "<<endl;
        cout << "2.- Crear Manualmente el Tablero "<<endl;
        cout << "---- Ingrese la opcion que Desea ";
        cin >> opcion;
        if (opcion == 1){
            int opcionScape = 0;
            do {
                Archivos *archivosaux = new Archivos();
                archivosaux->leecturaArchivoTablero();
                Juego juego(archivosaux->getFilas(),archivosaux->getColumnas(), archivosaux->getNiveles(), jugadorDir);
                juegoDir = &juego;
                juegoDir->llenarLista(archivosaux->getValoresLista());
                opcionScape =juegoDir->jugar();
                if (opcionScape == 1){
                    //calcular puntaje y reportes del juego
                    jugadorDir->setPuntaje(juegoDir->calculoPuntaje(filas,columnas,niveles));
                    archivos->guardarRegistro(jugadorDir);
                    cout << "------------------Punteo Obtenido------------------" <<endl;
                    cout << "--------Nombre: "<<jugadorDir->getNombre()<<endl;
                    cout << "--------Puntaje: "<<jugadorDir->getPuntaje()<<endl;
                    cout << "--------Pasos: "<<jugadorDir->getPasos()<<endl;
                    cout << "--------Tiempo: "<<jugadorDir->getSegundos()<<endl;
                    cout << "--------------------------------------------------------" <<endl<<endl;
                }
                if (opcionScape == 3){
                    opcion = 0;
                }
                delete archivosaux;
                delete juego.getLista();
                juego.~Juego();
            }while(opcionScape == 2);
        }else if (opcion == 2){
            cout << "Ingrese el numero de --filas: ";
            cin >> filas;
            cout << "Ingrese el numero de --columnas: ";
            cin >> columnas;
            cout << "Ingrese el numero de --niveles: ";
            cin >> niveles;
            if (filas>1 && columnas >1 && niveles >0 ){
                int opcionScape = 0;
                do {
                    Juego juego(filas,columnas, niveles, jugadorDir);
                    juegoDir = &juego;
                    juegoDir->llenarLista();
                    opcionScape =juegoDir->jugar();
                    if (opcionScape == 1){
                        //calcular puntaje y reportes del juego
                         jugadorDir->setPuntaje(juegoDir->calculoPuntaje(filas,columnas,niveles));
                         archivos->guardarRegistro(jugadorDir);
                        cout << "------------------Punteo Obtenido------------------" <<endl;
                        cout << "--------Nombre: "<<jugadorDir->getNombre()<<endl;
                        cout << "--------Puntaje: "<<jugadorDir->getPuntaje()<<endl;
                        cout << "--------Pasos: "<<jugadorDir->getPasos()<<endl;
                        cout << "--------Tiempo: "<<jugadorDir->getSegundos()<<endl;
                        cout << "--------------------------------------------------------" <<endl<<endl;
                    }
                    if (opcionScape == 3){
                        opcion = 0;
                    }
                    delete juego.getLista();
                    juego.~Juego();
                }while(opcionScape == 2);
            }else{
                cout << "Datos incorectos, filas >1 &  columnas >1  & Niveles >0 "<<endl<<endl;
                opcion = 0;
            }
        }else{
            opcion =0;
        }
    }
}

