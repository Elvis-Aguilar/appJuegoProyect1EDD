cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp object/Jugador.cpp object/Jugador.h juego/Juego.cpp juego/Juego.h listasOrtogonales/Nodo.cpp listasOrtogonales/Nodo.h listasOrtogonales/Lista.cpp listasOrtogonales/Lista.h archivos/Archivos.cpp archivos/Archivos.h)
