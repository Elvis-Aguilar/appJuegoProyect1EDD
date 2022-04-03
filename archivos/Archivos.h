/**
 * Created by elvis_agui on 3/04/22.
 */
#ifndef UNTITLED_ARCHIVOS_H
#define UNTITLED_ARCHIVOS_H


#include <string>
#include "../object/Jugador.h"
#include <iterator>
#include <vector>
#include <string>
using std::vector;
class Archivos {
public:
    void leecturaArchivo();
    void leecturaArchivoTablero();
    void separarCamposTable(std::string linea, bool);
    void guardarRegistro(Jugador *jugador1);
    void separarCampos(std::string linea);

    int *getValoresLista() const;

    void setValoresLista(int *valoresLista);

    int getFilas() const;

    void setFilas(int filas);

    int getColumnas() const;

    void setColumnas(int columnas);

    int getNiveles() const;

    void setNiveles(int niveles);

    virtual ~Archivos();
private:
    int *valoresLista;
    int filas;
    int columnas;
    int niveles;
    string linea;
    int iterador = 0;
    string texto;
};


#endif //UNTITLED_ARCHIVOS_H
