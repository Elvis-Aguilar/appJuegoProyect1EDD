//
// Created by elvis_agui on 25/03/22.
//

#include "Juego.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
using  namespace std;
Juego::Juego(int filas, int colimnas, int niveles, Jugador *jugadordir) : filas(filas), colimnas(colimnas),
                                                                          niveles(niveles), jugadordir(jugadordir) {
}

int Juego::getFilas() const {
    return filas;
}

void Juego::setFilas(int filas) {
    Juego::filas = filas;
}

int Juego::getColimnas() const {
    return colimnas;
}

void Juego::setColimnas(int colimnas) {
    Juego::colimnas = colimnas;
}

int Juego::getNiveles() const {
    return niveles;
}

void Juego::setNiveles(int niveles) {
    Juego::niveles = niveles;
}

Jugador *Juego::getJugadordir() const {
    return jugadordir;
}

void Juego::setJugadordir(Jugador *jugadordir) {
    Juego::jugadordir = jugadordir;
}

Lista *Juego::getLista() const {
    return lista;
}

void Juego::setLista(Lista *lista) {
    Juego::lista = lista;
}

/**
 * opciones de llenar la lista
 */
void Juego::llenarLista() {
    cout << ""<<endl;
    cout << "-------- OPCIONES PARA LLENAR EL TABLERO----------------- "<<endl;
    int opcion = 0;
    do {
        cout << "1.- LLENAR INGRESANDO LOS VALORES "<<endl;
        cout << "2.- LLENAR CON DATOS ALEATORIOS (automatico) "<<endl;
        cout << "---Digite la opcion:  ";
        cin >> opcion;
        if (opcion == 1){
            cout << "------------INDICACIONES DE INGRESO--------------"<<endl<<endl;
            cout << "1.- INTERVALO DE VALORES VALIDOS A INGRESAR:  "<<endl;
            cout << "--Valor minimo:  "<< 1<<"  --Valro maximo: "<<(filas*colimnas*niveles)-1<<endl<<endl;
            cout << "2.- NO SE ACEPTAN VALORES REPETIDOS  "<<endl;
            lista->crearLista(filas,colimnas,niveles,false);
            nodoJuego= lista->getUlitmoAbjo();
            nodoJuego = lista->getUlitmoSiguienteNodo(nodoJuego);
        }else if(opcion == 2){
            cout << "------------LLENANDO TABLERO--------------"<<endl<<endl;
            lista->crearLista(filas,colimnas,niveles, true);
            nodoJuego= lista->getUlitmoAbjo();
            nodoJuego = lista->getUlitmoSiguienteNodo(nodoJuego);
        }else{
            cout << "OPCION INVALIDA----------------------- "<<endl<<endl;
            opcion = 0;
        }
    }while(opcion == 0);
}

/**
 * logica del juego para moverse y sugerir movimientos
 * @return
 */
int Juego::jugar() {
    auto start = std::chrono::system_clock::now();
    cout << "--------QUE COMIENZE EL JUEGO-------------"<<endl;
    cout << "---Debes ordenar los numeros de forma Acendente o decendente---------"<<endl;
    cout << "---El Espacio con X debes mover tratando de ordenar lo numeros----------"<<endl;
    cout << "---Puedes terminar el juego en cualquier momento y elegir el calculo de puntaje (desendente o acendente)---------"<<endl;
    cout << "---Tambien puedes reiniciar el juego por completo o simplemente reiniciar desde la cracion del tablero -----------";
    cout << "-------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    int opcion = 1;
    int opcionesScape= 0;
    while(opcion != 0){
        cout << "---------Jugador: "<<jugadordir->getNombre()<<endl<<endl;
        lista->imprimirTablero(filas,colimnas, niveles);
        cout << ""<<endl;
        opcion = opcionesMovimiento();
        if (opcion != 0){
            moverNodo(opcion);
            pasos++;
        }else{
            opcionesScape = opcionseScape();
        }
    }
    auto end =std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = (end-start)/1000;
    int segundos=(int)duration.count()%60;
    jugadordir->setSegundos(segundos);
    jugadordir->setPasos(pasos);
    return  opcionesScape;

}

/**
 * muestra las posibles opciones de movimiento entre el tablero
 * @return
 */
int Juego::opcionesMovimiento() {
    int opciones = 0;
    bool opcionIncorecta = true;
    cout << "-------------------OPCIONES DE MOVIMIENTOS----------------------"<<endl;
    cout << "------Digite el valor de la casilla que desee mover (intercambiar posicion con la X)"<<endl;
    cout << "----- DIGITE --0-- PARA TERMINAR EL JUEGO O REINICIARLO "<<endl;
    cout << "----------------------------------------------------------------------------------------- "<<endl<<endl;
    do {
        int *valoreValidos = new int[6];
        cout << "-Posibles movimientos (solo estos valores puede ingresar, DIGITE --0-- PARA TERMINAR EL JUEGO O REINICIARLO)----------------------"<<endl;
        if (nodoJuego->getSiguiente() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getSiguiente()->getValor()<<endl;
            valoreValidos[0]=nodoJuego->getSiguiente()->getValor();
        }
        if (nodoJuego->getAnterior() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getAnterior()->getValor()<<endl;
            valoreValidos[1]=nodoJuego->getAnterior()->getValor();
        }
        if (nodoJuego->getArriba() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getArriba()->getValor()<<endl;
            valoreValidos[2]=nodoJuego->getArriba()->getValor();
        }
        if (nodoJuego->getAbajo() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getAbajo()->getValor()<<endl;
            valoreValidos[3]=nodoJuego->getAbajo()->getValor();
        }
        if (nodoJuego->getEnfrente() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getEnfrente()->getValor()<<endl;
            valoreValidos[4]=nodoJuego->getEnfrente()->getValor();
        }
        if (nodoJuego->getAtras() != nullptr){
            cout << "--- Casilla con valor: "<<nodoJuego->getAtras()->getValor()<<endl;
            valoreValidos[5]=nodoJuego->getAtras()->getValor();
        }
        cout << "----- DIGITE EL VALOR: ";
        cin>>opciones;
        cout << "";
        if (opciones == 0){
            opcionIncorecta = false;
        }else{
            for (int i = 0; i < 6; ++i) {
                if (valoreValidos[i] == opciones){
                    opcionIncorecta = false;
                    opciones = i+1;
                    break;
                }
            }
        }
        if (opcionIncorecta){
            cout << "----- Ups!! opcion incorrecta intentalo otra ves------------"<<endl<<endl;
        }
        delete[] valoreValidos;
    } while (opcionIncorecta);
    return opciones;
}

Juego::~Juego() {

}

/**
 * opciones de salir o reinicar el juego
 * @return
 */
int Juego::opcionseScape() {
    int opcion = 0;
    do {
        cout << "-------------------OPCIONES----------------------"<<endl;
        cout << "1.- terminar el Juego"<<endl;
        cout << "2.- Reinciar manteniendo la filas, columnas y niveles"<<endl;
        cout << "3.- Reiniciar desde la creacion del tablero"<<endl;
        cout << "Digite la opcion que decee: ";
        cin>> opcion;
    }while(opcion<1  ||  opcion>3);

    return opcion;
}

/**
 * hace el movimiento etre nodos
 * @param valorAMover
 */
void Juego::moverNodo(int valorAMover) {
    int valoAux;
    switch (valorAMover) {
        case 1:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getSiguiente()->getValor());
            nodoJuego->getSiguiente()->setValor(valoAux);
            nodoJuego = nodoJuego->getSiguiente();
            break;
        case 2:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getAnterior()->getValor());
            nodoJuego->getAnterior()->setValor(valoAux);
            nodoJuego = nodoJuego->getAnterior();
            break;
        case 3:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getArriba()->getValor());
            nodoJuego->getArriba()->setValor(valoAux);
            nodoJuego = nodoJuego->getArriba();
            break;
        case 4:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getAbajo()->getValor());
            nodoJuego->getAbajo()->setValor(valoAux);
            nodoJuego = nodoJuego->getAbajo();
            break;
        case 5:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getEnfrente()->getValor());
            nodoJuego->getEnfrente()->setValor(valoAux);
            nodoJuego = nodoJuego->getEnfrente();
            break;
        case 6:
            valoAux = nodoJuego->getValor();
            nodoJuego->setValor(nodoJuego->getAtras()->getValor());
            nodoJuego->getAtras()->setValor(valoAux);
            nodoJuego = nodoJuego->getAtras();
            break;
        default:
            break;
    }
}

/**
 * calcula el puntaje del juego
 * @param fila
 * @param colum
 * @param niveles
 * @return
 */
int Juego::calculoPuntaje(int fila, int colum, int niveles) {
    int puntaje = 0;
    int posicion = 1;
    Nodo *nodofila = lista->getHead();
    Nodo *nodoCulumna = lista->getHead();
    Nodo *nodoNivel = lista->getHead();
    for (int z= 0; z < niveles; ++z) {
        for (int i = 0; i < fila; ++i) {
            for (int j = 0; j < colum; ++j) {
                if (nodoCulumna->getValor() == posicion){
                    puntaje+=2;
                }
                posicion++;
                nodoCulumna = nodoCulumna->getSiguiente();
            }
            nodofila = nodofila->getAbajo();
            nodoCulumna = nodofila;
        }
        nodoNivel = nodoNivel->getAtras();
        nodofila = nodoNivel;
        nodoCulumna = nodofila;
    }

    return puntaje;
}

void Juego::llenarLista(int *vlues) {
    lista->crearLista(filas,colimnas,niveles, vlues);
    nodoJuego= lista->getUlitmoAbjo();
    nodoJuego = lista->getUlitmoSiguienteNodo(nodoJuego);
}




