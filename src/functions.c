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

//função esperar para que o usuário pressione enter(interface)
void esperar() {
    printf(ROXO"\nPressione Enter para continuar..."FIM_COR);
    while (getchar() != '\n');
    getchar();  
}
//Cor do terminal
#define ROXO "\e[1;34m"
#define FIM_COR "\e[0m"