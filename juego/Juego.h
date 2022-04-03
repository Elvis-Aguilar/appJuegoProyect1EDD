/**
 * Created by elvis_agui on 25/03/22
 */
#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H
#include "../object/Jugador.h"
#include "../listasOrtogonales/Lista.h"

class Juego {
private:
    int filas, colimnas, niveles, pasos=0;
    Jugador *jugadordir;
    Lista *lista = new Lista();
    Nodo *nodoJuego;
public:
    Juego(int filas, int colimnas, int niveles, Jugador *jugadordir);

    void llenarLista();

    void llenarLista(int *);

    int opcionesMovimiento();

    int opcionseScape();

    int jugar();

    void moverNodo(int);

    int calculoPuntaje(int fila, int colum, int niveles);

    int getFilas() const;

    void setFilas(int filas);

    int getColimnas() const;

    void setColimnas(int colimnas);

    int getNiveles() const;

    void setNiveles(int niveles);

    Jugador *getJugadordir() const;

    void setJugadordir(Jugador *jugadordir);

    Lista *getLista() const;

    void setLista(Lista *lista);

    virtual ~Juego();
};


#endif //UNTITLED_JUEGO_H
