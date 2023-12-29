#ifndef MORSE
#define MORSE

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#ifdef _WIN32
    #include <windows.h>
#endif


// Protótipos de Funções
void morseAudio(char *morse);

#endif