/**
 * Created by elvis_agui on 26/03/22.
 */

#include "Lista.h"
#include <iostream>
#include <stdlib.h>
using  namespace std;

/**
 * crea la lista, dependienedo las filas columnas y niveles, itera las mismas con un for
 * @param filas
 * @param columnas
 * @param niveles
 * @param aleatorio
 */
void Lista::crearLista(int filas, int columnas, int niveles, bool aleatorio) {
    Nodo *aux1, *aux2, *aux3, *aux4;
    int vlaMax = (filas*columnas*niveles)-1;
    int *arreglo = new int[vlaMax];
    for (int k = 0; k < vlaMax; ++k) {
        arreglo[k]=0;
    }
    for (int z = 0; z < niveles; ++z) {
        if (!aleatorio){
            cout << "\n-----INGRESA LOS VALORES DEL NIVEL "<<z+1<<"--------"<<endl;
        }
        for (int i = 0; i < filas ; ++i) {
            for (int j = 0; j < columnas; ++j) {
                aux1 = new Nodo();
                if ( i == filas-1 && j == columnas-1 && z == 0) {
                    int valor = -1;
                    aux1->setValor(valor);
                }else{
                    pedirValor(aux1,i,j, aleatorio, arreglo, vlaMax);
                }
                insertarNodo(i,j,z,aux1,aux2,aux3,aux4);
            }
        }
    }
    delete[] arreglo;
}

Nodo *Lista::getHead() const {
    return head;
}

void Lista::setHead(Nodo *head) {
    Lista::head = head;
}

Lista::Lista() {
    head = nullptr;
}

/**
 * busca el ultimos siguiente(ultimo a la derecha) del head
 * @return nodo ultimo a la derecha
 */
Nodo *Lista::getUltimoSiguiente() {
    Nodo *ultimo = head;
    while (ultimo->getSiguiente() != nullptr){
        ultimo = ultimo->getSiguiente();
    }
    return ultimo;
}

/**
 * busca el ultimo nodo abajo desde el head
 * @return
 */
Nodo *Lista::getUlitmoAbjo() {
    Nodo *ulitmo = head;
    while (ulitmo->getAbajo() != nullptr){
        ulitmo = ulitmo->getAbajo();
    }
    return ulitmo;
}

/**
 * ultimo a la derecha desde un nodo en especifico
 * @param nodo
 * @return
 */
Nodo *Lista::getUlitmoSiguienteNodo(Nodo *nodo) {
    Nodo *ulitmo = nodo;
    while (ulitmo->getSiguiente() != nullptr){
        ulitmo = ulitmo->getSiguiente();
    }
    return ulitmo;
}

/**
 * imprime la lista la itera con for
 * @param filas
 * @param columna
 * @param niveles
 */
void Lista::imprimirTablero(int filas, int columna, int niveles) {
    Nodo *nodofila = head;
    Nodo *nodoCulumna = head;
    Nodo *nodoNivel = head;
    for (int z = 0; z < niveles; ++z) {
        cout << "\tNIVEL "<<z+1<<endl;
        cout << "\t_";
        for (int i = 0; i < columna; ++i) {
            cout << "_________";
        }
        cout << ""<<endl;
        for (int i = 0; i < filas ; ++i) {
            cout<< "\t|";
            for (int j = 0; j < columna; ++j) {
                cout <<"  ";
                if (nodoCulumna->getValor()< 100){
                    if (nodoCulumna->getValor() < 10){
                        if (nodoCulumna->getValor() == -1){
                            cout<<"  "<<"X"<<"   ";
                        }else{
                            cout<<"  "<<nodoCulumna->getValor() <<"   ";
                        }
                    }else{
                        cout<<" "<<nodoCulumna->getValor() <<"   ";
                    }
                }else{
                    cout<<""<<nodoCulumna->getValor() <<"   ";
                }
                cout << "|";
                nodoCulumna = nodoCulumna->getSiguiente();
            }
            cout << ""<<endl;
            cout << "\t_";
            for (int i = 0; i < columna; ++i) {
                cout << "_________";
            }
            cout << ""<<endl;
            nodofila = nodofila->getAbajo();
            nodoCulumna = nodofila;
        }
        nodoNivel = nodoNivel->getAtras();
        nodofila = nodoNivel;
        nodoCulumna = nodofila;
    }

}

/**
 * ultimo atras desde el head
 * @return
 */
Nodo *Lista::getUltimoAtras() {
    Nodo *ulitmo = head;
    while (ulitmo->getAtras() != nullptr){
        ulitmo = ulitmo->getAtras();
    }
    return ulitmo;
}

/**
 * ultimo nodo abajo desde un nodo en especifico
 * @param nodo
 * @return
 */
Nodo *Lista::getUltimoAbajoNodo(Nodo *nodo) {
    Nodo *ulitmo = nodo;
    while (ulitmo->getAbajo() != nullptr){
        ulitmo = ulitmo->getAbajo();
    }
    return ulitmo;
}

/**
 * pide el valor a insertar o lo genera eleatoriamene
 * @param aux1
 * @param i
 * @param j
 * @param aleatorio
 * @param arreglo
 * @param valMax
 */
void Lista::pedirValor(Nodo *aux1, int i, int j, bool aleatorio, int *arreglo, int valMax) {
    int valor = 0;
    bool otro = true;
    if (aleatorio){
        //srand(time(NULL));
        while (otro){
            valor = 1 + rand() % (valMax);
            if (valor <= valMax){
                if (arreglo[valor-1] == 0){
                    arreglo[valor-1]= valor;
                    otro = false;
                }
            }
        }
        aux1->setValor(valor);
    }else{
        while (otro){
            cout << "Valor en -fila: "<<i+1<<" -Columna "<<j+1<<" --  ";
            cin >> valor;
            if (valor <= valMax){
                if (arreglo[valor-1] == 0){
                    arreglo[valor-1]= valor;
                    otro = false;
                }else{
                    cout << "UPS!!! VALOR INVALIDO "<<endl<<endl;
                    cout << "Los valores ya agregados son: "<<endl;
                    for (int k = 0; k < valMax; ++k) {
                        if (arreglo[k] != 0){
                            cout << "---> "<<arreglo[k]<<" ";
                        }
                    }
                    cout << ""<<endl;
                    cout << "INTENTALO OTRA VES :) "<<endl<<endl;
                }
            } else{
                cout << "UPS!!! VALOR INVALIDO: Exediste el valor maximo "<<endl<<endl;
                cout << "El valor Maximo es: "<< valMax<<endl;
                cout << "INTENTALO OTRA VES :) "<<endl<<endl;
            }
        }
        aux1->setValor(valor);
    }
}

/**
 * inserta un nuevo nodo en la lista
 * @param i
 * @param j
 * @param z
 * @param aux1
 * @param aux2
 * @param aux3
 * @param aux4
 */
void Lista::insertarNodo(int i, int j, int z, Nodo *aux1, Nodo *aux2, Nodo *aux3, Nodo *aux4) {
    if (j == 0 && i == 0){
        if (z == 0){
            head = aux1;
        }else{
            aux4 = getUltimoAtras();
            aux1->setEnfrente(aux4);
            aux4->setAtras(aux1);
        }
    }
    if (j == 0 && i != 0)  {
        insertarNodoColumn1(z,aux1,aux2,aux4);
    }
    if (i ==0 && j != 0){
        insertarNodofiala1(z,aux1,aux3,aux4);
    }
    if (i !=0 && j != 0 ){
        insertarNodoPosN(z,aux1,aux2,aux4);
    }
}

/**
 * inserta un nodo en la columna 1 iterando entre filas n
 * @param z
 * @param aux1
 * @param aux2
 * @param aux4
 */
void Lista::insertarNodoColumn1(int z, Nodo *aux1, Nodo *aux2, Nodo *aux4) {
    if (z == 0){
        aux2 = getUlitmoAbjo();
        aux2->setAbajo(aux1);
        aux2->getAbajo()->setArriba(aux2);
    }else{
        aux4 = getUltimoAtras();
        aux4 = getUltimoAbajoNodo(aux4);
        aux4->setAbajo(aux1);
        aux4->getAbajo()->setArriba(aux4);
        aux4->getEnfrente()->getAbajo()->setAtras(aux4->getAbajo());
        aux4->getAbajo()->setEnfrente(aux4->getEnfrente()->getAbajo());
    }
}

/**
 * inserta el nodo en la fila 1 y columna n
 * @param z
 * @param aux1
 * @param aux3
 * @param aux4
 */
void Lista::insertarNodofiala1(int z, Nodo *aux1, Nodo *aux3, Nodo *aux4) {
    if (z == 0){
        aux3 = getUltimoSiguiente();
        aux3->setSiguiente(aux1);
        aux3->getSiguiente()->setAnterior(aux3);
    }else{
        aux4 = getUltimoAtras();
        aux4 = getUlitmoSiguienteNodo(aux4);
        aux4->setSiguiente(aux1);
        aux4->getSiguiente()->setAnterior(aux4);
        aux4->getEnfrente()->getSiguiente()->setAtras(aux4->getSiguiente());
        aux4->getSiguiente()->setEnfrente(aux4->getEnfrente()->getSiguiente());
    }
}

/**
 * inserta un nodo en cualquier lugar que no sea columna 1 y fila 1
 * @param z
 * @param aux1
 * @param aux2
 * @param aux4
 */
void Lista::insertarNodoPosN(int z, Nodo *aux1, Nodo *aux2, Nodo *aux4) {
    if (z == 0){
        aux2 = getUlitmoAbjo();
        aux2= getUlitmoSiguienteNodo(aux2);
        aux2->setSiguiente(aux1);
        aux2->getSiguiente()->setAnterior(aux2);
        aux2->getArriba()->getSiguiente()->setAbajo(aux2->getSiguiente());
        aux2->getSiguiente()->setArriba(aux2->getArriba()->getSiguiente());
    }else{
        aux4 = getUltimoAtras();
        aux4 = getUltimoAbajoNodo(aux4);
        aux4 = getUlitmoSiguienteNodo(aux4);
        aux4->setSiguiente(aux1);
        aux4->getSiguiente()->setAnterior(aux4);
        aux4->getArriba()->getSiguiente()->setAbajo(aux4->getSiguiente());
        aux4->getSiguiente()->setArriba(aux4->getArriba()->getSiguiente());
        aux4->getEnfrente()->getSiguiente()->setAtras(aux4->getSiguiente());
        aux4->getSiguiente()->setEnfrente(aux4->getEnfrente()->getSiguiente());
    }
}

Lista::~Lista() {

}

/**
 * crea la lista desde un arreglo de valores que introducira
 * @param filas
 * @param columnas
 * @param niveles
 * @param listValues
 */
void Lista::crearLista(int filas, int columnas, int niveles, int *listValues) {
    Nodo *aux1, *aux2, *aux3, *aux4;
    int iterado = 0;
    for (int z = 0; z < niveles; ++z) {
        for (int i = 0; i < filas ; ++i) {
            for (int j = 0; j < columnas; ++j) {
                aux1 = new Nodo();
                if ( i == filas-1 && j == columnas-1 && z == 0) {
                    int valor = -1;
                    iterado++;
                    aux1->setValor(valor);
                }else{
                    int valor  = listValues[iterado];
                    aux1->setValor(valor);
                    iterado++;
                }
                insertarNodo(i,j,z,aux1,aux2,aux3,aux4);
            }
        }
    }
}
