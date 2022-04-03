/**
 * Created by elvis_agui on 25/03/22.
 */

#ifndef UNTITLED_NODO_H
#define UNTITLED_NODO_H


class Nodo {
    private:
        int valor;
        Nodo *siguiente;
        Nodo *anterior;
        Nodo *arriba;
        Nodo *abajo;
        Nodo *enfrente;
        Nodo *atras;
    public:
    Nodo();

    int getValor() const;

    void setValor(int valor);

    Nodo *getSiguiente() const;

    void setSiguiente(Nodo *siguiente);

    Nodo *getAnterior() const;

    void setAnterior(Nodo *anterior);

    Nodo *getArriba() const;

    void setArriba(Nodo *arriba);

    Nodo *getAbajo() const;

    void setAbajo(Nodo *abajo);

    Nodo *getEnfrente() const;

    void setEnfrente(Nodo *enfrente);

    Nodo *getAtras() const;

    void setAtras(Nodo *atras);

    virtual ~Nodo();


};


#endif //UNTITLED_NODO_H
