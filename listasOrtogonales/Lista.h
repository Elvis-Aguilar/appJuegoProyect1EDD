/**
 * Created by elvis_agui on 26/03/22.
 */

#ifndef UNTITLED_LISTA_H
#define UNTITLED_LISTA_H
#include "Nodo.h"

class Lista {
    private:
        Nodo *head;
    public:

    Lista();

    virtual ~Lista();

    Nodo* getUltimoSiguiente();

    Nodo* getUlitmoAbjo();

    Nodo* getUltimoAtras();

    Nodo* getUltimoAbajoNodo(Nodo *nodo);

    Nodo* getUlitmoSiguienteNodo(Nodo * nodo);

    void pedirValor(Nodo * nodo,int,int, bool, int*, int);

    void insertarNodo(int i, int j, int z, Nodo*,Nodo*,Nodo*,Nodo*);

    void insertarNodoColumn1(int z, Nodo*, Nodo*, Nodo*);

    void insertarNodofiala1(int z, Nodo*, Nodo*, Nodo*);

    void insertarNodoPosN(int z, Nodo*, Nodo*, Nodo*);

    void imprimirTablero(int filas, int columna, int niveles);

    void crearLista(int filas, int columna, int niveles, bool);

    void crearLista(int filas, int columna, int niveles, int*);
        Nodo *getHead() const;
        void setHead(Nodo *head);
};




#endif //UNTITLED_LISTA_H
