/**
 * Created by elvis_agui on 25/03/22.
 */

#ifndef UNTITLED_JUGADOR_H
#define UNTITLED_JUGADOR_H
#include <strings.h>
#include <string>
using std::string;

class Jugador {
    private:
        int puntaje;
        char *nombre;
        int segundos;
        int pasos;
        string nombreAux;

    public:
    Jugador(int puntaje, char *nombre, int segundos);

    int getPuntaje() const;

    void setPuntaje(int puntaje);

    char *getNombre() const;

    void setNombre(char *nombre);

    virtual ~Jugador();

    int getSegundos() const;

    void setSegundos(int segundos);

    int getPasos() const;

    void setPasos(int pasos);

    const string &getNombreAux() const;

    void setNombreAux(const string &nombreAux);
};


#endif //UNTITLED_JUGADOR_H
