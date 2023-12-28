#include "../include/morse.h"

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