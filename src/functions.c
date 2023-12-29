#include "../include/morse.h"

// lerPorClique: lê através do input (teclado) por cliques um código morse e o coloca em palavra
// para os caracteres deve-se segurar a tecla enter
// '.' -> segurar enter por aproximadamente 1 segundo
// '-' -> segurar enter por aproximadamente 2 segundos
// deve haver um intervalo de aproximadamente 1 segundo entre um dígito e outro
// ' ' -> manter o enter solto por aproximadamente 3 segundos
// para parar a leitura, digite qualquer letra e pressiona enter
void lerPorClique(char *palavra) {
    // essa struct utiliza da biblioteca sys/time.h para calcular o tempo entre os inputs do teclado
    struct timeval begin, end;
    double tempoSec;
    int soma = 0, i = 0;

    getchar();
    gettimeofday(&begin, 0);
    
    // esse loop externo roda enquanto houverem caracteres a serem lidos
    while (1) {
        int parar = 0;

        // esse loop roda enquanto estiver em um mesmo dígito
        while (1) {
            if (getchar() != '\n') {
                parar = 1;
                break;
            }

            gettimeofday(&end, 0);
            tempoSec = (double) (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) * 1e-6;
            printf("tempo: %lf\n", tempoSec);
            if (tempoSec > 0.4) {
                printf("nova letra\n");
                break;
            }

            // a quantidade de enters é usada para saber se é um ponto ou um traço
            soma++;
            printf("soma: %d\n", soma);

            gettimeofday(&begin, 0);
        }
        if (soma == 0) {
            palavra[i++] = '.';
        } else {
            palavra[i++] = '-';
        }

        if (parar == 1) {
            palavra[i] = '\0';
            break;
        }

        if (tempoSec > 2) {
            palavra[i++] = ' ';
        }
        
        soma = 0;
        gettimeofday(&begin, 0);
    }
}