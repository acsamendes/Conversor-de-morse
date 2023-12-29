#ifndef MORSE
#define MORSE

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>

// Variáveis Globais
#define ROXO "\e[1;34m"
#define FIM_COR "\e[0m"

// Protótipos de Funções
void lerPorClique(char *palavra);

void conv_MorseParaAlfaNumerico(char *morse);

#endif