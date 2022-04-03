//
// Created by elvis_agui on 25/03/22.
//

#include "Jugador.h"



int Jugador::getPuntaje() const {
    return puntaje;
}

void Jugador::setPuntaje(int puntaje) {
    Jugador::puntaje = puntaje;
}

Jugador::~Jugador() {

}

int Jugador::getSegundos() const {
    return segundos;
}

void Jugador::setSegundos(int segundos) {
    Jugador::segundos = segundos;
}




char *Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(char *nombre) {
    Jugador::nombre = nombre;
}

Jugador::Jugador(int puntaje, char *nombre, int segundos) : puntaje(puntaje), nombre(nombre), segundos(segundos) {}

const string &Jugador::getNombreAux() const {
    return nombreAux;
}

void Jugador::setNombreAux(const string &nombreAux) {
    Jugador::nombreAux = nombreAux;
}

int Jugador::getPasos() const {
    return pasos;
}

void Jugador::setPasos(int pasos) {
    Jugador::pasos = pasos;
}
