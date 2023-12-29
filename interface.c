//funçoes alfanumerico para morse e morse para alfanumerico.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROXO "\e[1;34m"
#define FIM_COR "\e[0m"

void clear(){
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}
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

void menu() {
    printf(ROXO"\t\t========= CONVERSOR MORSE =========\n\n"FIM_COR);
    printf(ROXO"1 - "FIM_COR);
    printf("Alfanumerico para Morse\n");
    printf(ROXO"2 - "FIM_COR);
    printf("Morse para Alfanumerico\n");
    printf(ROXO"3 - "FIM_COR);
    printf("Como funciona o codigo morse?\n");
    printf(ROXO"0 - "FIM_COR);
    printf("Sair\n");
   
}
void esperar() {
    printf(ROXO"\nPressione Enter para continuar..."FIM_COR);
    while (getchar() != '\n');
    getchar();  
}
int main() {

    int escolha;
    char entrada[100];

    do {
        clear();
        menu();
        printf("\nEscolha a operacao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                clear();
                printf(ROXO"-------- Alfanumerico para Morse --------\n\n"FIM_COR);
                printf("Digite o valor alfanumerico: ");
                printf("\nResultado em Morse: \n");
                esperar();
                break;
            case 2:
                clear();
                printf(ROXO"------- Morse para Alfanumerico -------\n\n"FIM_COR);
                printf("Digite o valor Morse: ");
                scanf("%s", entrada);
                printf("\nResultado em alfanumerico: ");
                conv_MorseParaAlfaNumerico(entrada);
                esperar();
                break;
            case 3:
                clear();
                printf(ROXO"COMO FUNCIONA O CODIGO MORSE?\n\n"FIM_COR);
                printf("O codigo Morse e um sistema de codificao de caracteres alfanumericos que utiliza sequencias de pulsos curtos\n");
                printf("e longos, geralmente representados por pontos e tracos, para representar letras, numeros e sinais de pontuacao.\n");
                printf("\n");
                printf("A codificacao Morse atribui combinacoes unicas de pontos e tracos a cada letra, numero e simbolo.\n");
                printf("As regras basicas sao as seguintes:\n");
                printf("\n");
                printf("Ponto (.) representa um sinal curto ou duracao curta.\n");
                printf("Traco (-) representa um sinal longo ou duracao longa.\n");
                printf("As letras e numeros sao representados por sequencias especificas de pontos e tracos.\n");
                printf("\n");
                printf("Por exemplo:\n");
                printf("A e representado por '.-'\n");
                printf("B e representado por '-...'\n");
                printf("1 e representado por '.----'\n");
                printf("\n");
                printf("Existem tambem regras para separar letras e palavras. Um espaco simples e usado\n");
                printf("para separar letras, enquanto um espaco mais longo (equivalente a sete pontos) e\n");
                printf("usado para separar palavras.\n");
                printf("\n");
                esperar();
                break;
            case 0:
                clear();
                printf(ROXO"Obrigado por utilizar o nosso conversor, ate breve!\n"FIM_COR);
                break;

            default:
                printf(ROXO"Opcao invalida. Tente novamente.\n"FIM_COR);
                esperar();

        }
    } while (escolha != 0);

    return 0;
}
