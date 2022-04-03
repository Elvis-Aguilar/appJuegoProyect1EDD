/**
 * Created by elvis_agui on 25/03/22.
 */

#include "Nodo.h"

Nodo::Nodo() {
    valor = 0;
    siguiente = nullptr;
    anterior = nullptr;
    arriba = nullptr;
    abajo = nullptr;
    enfrente = nullptr;
    atras = nullptr;
}

Nodo::~Nodo() {

}

int Nodo::getValor() const {
    return valor;
}

void Nodo::setValor(int valor) {
    Nodo::valor = valor;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}

Nodo *Nodo::getAnterior() const {
    return anterior;
}

void Nodo::setAnterior(Nodo *anterior) {
    Nodo::anterior = anterior;
}

Nodo *Nodo::getArriba() const {
    return arriba;
}

void Nodo::setArriba(Nodo *arriba) {
    Nodo::arriba = arriba;
}

Nodo *Nodo::getAbajo() const {
    return abajo;
}

void Nodo::setAbajo(Nodo *abajo) {
    Nodo::abajo = abajo;
}

Nodo *Nodo::getEnfrente() const {
    return enfrente;
}

void Nodo::setEnfrente(Nodo *enfrente) {
    Nodo::enfrente = enfrente;
}

Nodo *Nodo::getAtras() const {
    return atras;
}

void Nodo::setAtras(Nodo *atras) {
    Nodo::atras = atras;
}



