/**
 * Created by elvis_agui on 3/04/22.
 */
#include "Archivos.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::stringstream;
using namespace std;



/**
 * guarda el resgistro de cada juego
 * @param jugador1
 */
void Archivos::guardarRegistro(Jugador *jugador1) {
    ofstream archivo;
    archivo.open("registro.txt",ios::out | ios::app);
    if (archivo.fail()){
        cout<<"Error al intentar abrir el arhivos"<< endl;
    }
    archivo<<jugador1->getNombre()<<","<<jugador1->getPuntaje()<<","<<jugador1->getPasos()<<","<<jugador1->getSegundos()<<","<<"\n";
    archivo.close();
}

/**
 * lee el archivo para poder mostrar los reportes
 */
void Archivos::leecturaArchivo() {
    ifstream archivo("registro.txt");
    int pos = 1;
    while (getline(archivo,linea)){
        cout << "JUGADOR -#"<<pos<<endl;
        separarCampos(linea);
        pos++;
    }
    if (archivo.fail()){
        cout << "-----------------------------------------"<<endl;
    }


}

/**
 * imprime cada jugador separando nombr epuntaje y tiempo, la linea es cada jugador del archivo
 * @param linea
 */
void Archivos::separarCampos(std::string linea) {
    string text = linea;
    string nombre ;
    int puntaje;
    int tiempo;
    int pasos;
    string space_delimiter = ",";
    vector<string> words{};
    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    int cont = 0;
    for (const auto &str : words) {
        if (cont == 0){
            nombre = str;
            cont++;
        }else if (cont == 1){
            puntaje = stoi(str);
            cont++;
        }else if (cont == 2){
            pasos = stoi(str);
            cont++;
        }else{
            tiempo = stoi(str);
            cont++;
        }
    }
    cout << "--------Nombre: "<<nombre<<endl;
    cout << "--------Puntaje: "<<puntaje<<endl;
    cout << "--------Pasos: "<<pasos<<endl;
    cout << "--------Tiempo Seg: "<<tiempo<<endl;
}

Archivos::~Archivos() {

}

int *Archivos::getValoresLista() const {
    return valoresLista;
}

void Archivos::setValoresLista(int *valoresLista) {
    Archivos::valoresLista = valoresLista;
}

int Archivos::getFilas() const {
    return filas;
}

void Archivos::setFilas(int filas) {
    Archivos::filas = filas;
}

int Archivos::getColumnas() const {
    return columnas;
}

void Archivos::setColumnas(int columnas) {
    Archivos::columnas = columnas;
}

int Archivos::getNiveles() const {
    return niveles;
}

void Archivos::setNiveles(int niveles) {
    Archivos::niveles = niveles;
}

/**
 * lee el archov del tablero
 */
void Archivos::leecturaArchivoTablero() {
    bool isPrimerLinea = true;
    ifstream archivo("tablero.txt");
    while (getline(archivo,linea)){
        if (isPrimerLinea){
            separarCamposTable(linea, isPrimerLinea);
            int tam = niveles*filas*columnas;
            valoresLista = new int[tam];
            isPrimerLinea = false;
        }else{
            separarCamposTable(linea, isPrimerLinea);
        }
    }
    if (archivo.fail()){
        cout << "-----------------------------------------"<<endl;
    }
}

/**
 * separa los numeros para el tablero, y los guarda en un arrglo
 * @param linea
 * @param isPrimerLinea
 */
void Archivos::separarCamposTable(std::string linea, bool isPrimerLinea) {
    string text = linea;
    string space_delimiter = ",";
    vector<string> words{};
    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    int contador = 0;
    for (const auto &str: words) {
        if (isPrimerLinea) {
            if (contador == 0){
                filas = stoi(str);
                contador++;
            }else if (contador == 1){
                columnas = stoi(str);
                contador++;
            }else{
                niveles = stoi(str);
                contador++;
            }
        }else{
            valoresLista[iterador] =  stoi(str);
            iterador++;
        }
    }
}





