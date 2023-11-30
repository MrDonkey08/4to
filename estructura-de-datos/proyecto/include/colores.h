/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/ 

#ifndef ERRORES_H 
#define ERRORES_H

#include<iostream>

using std::cout;

// Definición de códigos de escape ANSI para colores en la consola de Linux
#ifdef _WIN32
#include <windows.h>
#else
// Definición de códigos de escape ANSI para colores en la consola de Linux
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_PURPLE "\x1b[35m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#endif

inline void azul() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
#else
    cout << ANSI_COLOR_BLUE;
#endif
}

inline void blanco() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#else
    cout << ANSI_COLOR_WHITE;
#endif
}

inline void rojo() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
#else
    cout << ANSI_COLOR_RED;
#endif
}

inline void purpura() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);
#else
    cout << ANSI_COLOR_PURPLE;
#endif
}

inline void amarillo() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
#else
    cout << ANSI_COLOR_YELLOW;
#endif
}

inline void verde() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
#else
    cout << ANSI_COLOR_GREEN;
#endif
}

#endif