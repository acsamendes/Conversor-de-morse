#include "../include/morse.h"

// lerPorClique: lê um código morse através do input (teclado) por cliques e o coloca em palavra
// deve-se utilizar a tecla enter
// '.' -> pressione o enter uma vez
// '-' -> segure a tecla até que ao menos mais um enter saia no input
// deve haver um intervalo de aproximadamente meio segundo entre um dígito e outro
// ' ' -> manter a tecla solta por aproximadamente 3 segundos
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

//funcao para a conversao de morse para alfanumerico
void conv_MorseParaAlfaNumerico(char *morse){
    char *alfabeto[27] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    char *numeros[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    char *caractere = strtok((char *)morse, " ");
    
    while (caractere != NULL){
        int i;
        int encontrado = 0;

        for (i = 0; i < 27; i++) {
            if (strcmp(caractere, alfabeto[i]) == 0) {
                if (i == 26) {
                    printf(" ");
                    encontrado = 1;
                    break;
                } else {
                    printf("%c", 'A' + i);
                    encontrado = 1;
                    break;
                }
            }
        }

        for (i = 0; i < 10; i++) {
            if (strcmp(caractere, numeros[i]) == 0) {
                printf("%d", i);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("(?)");
        }

        caractere = strtok(NULL, " ");
    }
}

//função para limpar a tela
void clear(){
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

//função para mostar o menu
void menu() {
    printf(ROXO"\t\t========= Conversor Morse =========\n\n"FIM_COR);
    printf("1. Alfanumerico para Morse\n");
    printf("2. Morse para Alfanumerico\n");
    printf("3. Como funciona o codigo morse?\n");
    printf("0. Sair\n");
}

//função esperar para que o usuário pressione enter(interface)
void esperar() {
    printf(ROXO"\nPressione Enter para continuar..."FIM_COR);
    while (getchar() != '\n');
    getchar();  
}

//Cor do terminal
#define ROXO "\e[1;34m"
#define FIM_COR "\e[0m"
