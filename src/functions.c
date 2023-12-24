#include "../include/morse.h"

// lerPorClique: lê através do input (teclado) por cliques um código morse e o coloca em palavra
// para os caracteres deve-se segurar a tecla enter
// '.' -> segurar enter por aproximadamente 1 segundo
// '-' -> segurar enter por aproximadamente 2 segundos
// deve haver um intervalo de aproximadamente 1 segundo entre um dígito e outro
// ' ' -> manter o enter solto por aproximadamente 3 segundos
// para parar a leitura, digite qualquer letra e pressiona enter
void lerPorClique(char *palavra) {
    clock_t tempo;
    int soma = 0, i = 0;

    // esse loop externo roda enquanto houverem caracteres a serem lidos
    while (1) {
        int parar = 0;
        getchar();
        tempo = clock();

        // esse loop roda enquanto estiver em um mesmo dígito
        while (1) {
            if (getchar() != '\n') {
                parar = 1;
                break;
            }

            tempo = clock() - tempo;
            if (((double)tempo) / CLOCKS_PER_SEC > 0.8) {
                break;
            }

            // a quantidade de enters é usada para saber se é um ponto ou um traço
            soma++;

            tempo = clock();
        }
        if (soma < 20) {
            palavra[i++] = '.';
        } else {
            palavra[i++] = '-';
        }

        if (parar == 1) {
            palavra[i] = '\0';
            break;
        }

        if (((double)tempo) / CLOCKS_PER_SEC > 2.5) {
            palavra[i++] = ' ';
        }
        
        soma = 1;
    }
}