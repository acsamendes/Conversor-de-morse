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

void menu() {
    printf(ROXO"\t\t========= Conversor Morse =========\n\n"FIM_COR);
    printf("1. Alfanumerico para Morse\n");
    printf("2. Morse para Alfanumerico\n");
    printf("3. Como funciona o codigo morse?\n");
    printf("0. Sair\n");
}
void esperar() {
    printf(ROXO"\nPressione Enter para continuar..."FIM_COR);
    while (getchar() != '\n');
    getchar();  
}
int main() {

    int escolha;

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
                printf("\nResultado em alfanumerico: \n");
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
