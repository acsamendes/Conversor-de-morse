#ifndef MORSE
#define MORSE


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#ifdef _WIN32
    #include <windows.h>
#endif


// Variáveis Globais
#define ROXO "\e[1;34m"
#define FIM_COR "\e[0m"


// Protótipos de Funções
void lerPorClique(char *palavra);
void morseAudio(char *morse);

void conv_MorseParaAlfaNumerico(char *morse);
char* conv_AlfaNumericoToMorse(char *string);

void clear();
void menu();
void esperar();

void limparBuffer();

#endif