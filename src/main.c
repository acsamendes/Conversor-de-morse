#include "../include/morse.h"

int main() {
    char escolha;
    char entrada[100];

    do {
        clear();
        menu();
        printf("\nEscolha a operacao: ");
        scanf("%c", &escolha);
        limparBuffer();

        switch (escolha) {
            case '1':
                clear();
                printf(ROXO"-------- Alfanumerico para Morse --------\n\n"FIM_COR);
                printf("Digite o valor alfanumerico: ");
                scanf(" %[^\n]", entrada);
                printf("\nResultado em Morse: \n");
                conv_AlfaNumericoToMorse(entrada);
                esperar();
                break;
            case '2':
                clear();
                printf(ROXO"------- Morse para Alfanumerico -------\n\n");

                printf("1 - "FIM_COR);
                printf("Digitar o código morse\n");
                printf(ROXO"2 - "FIM_COR);
                printf("Leitura por cliques\n");
                printf("\nEscolha a operacao: ");
                scanf("%c", &escolha);
                limparBuffer();

                switch (escolha) {
                    case '1':
                        clear();
                        printf(ROXO"------- Morse para Alfanumerico -------\n\n"FIM_COR);
                        printf("Digite o valor Morse: ");
                        scanf(" %[^\n]", entrada);
                        printf("\nResultado em alfanumerico: ");
                        conv_MorseParaAlfaNumerico(entrada);
                        esperar();
                        break;
                    case '2':
                        clear();
                        printf(ROXO"------- Morse para Alfanumerico -------\n\n"FIM_COR);
                        printf("Para utilizar o leitor por cliques, siga as seguintes diretrizes:\n");
                        printf("Utilize a tecla 'enter' para a leitura da string.\n");
                        printf("Pressione-a uma vez para colocar um '.'.\n");
                        printf("Segure a tecla por um tempo para colocar um '-'.\n");
                        printf("Deve haver um intervalo de meio segundo entre diferentes caracteres.\n");
                        printf("Deve haver um intervalo de 3 segundos entre uma letra e outra.\n");
                        printf("Deve haver um intervalo de 5 segundos entre uma palavra e outra.\n");
                        printf("Para parar a leitura, digite qualquer letra e pressione enter.\n");
                        esperar();

                        clear();
                        printf("Digite o morse por cliques: \n");
                        lerPorClique(entrada);
                        printf("Morse lida: %s", entrada);
                        printf("\nResultado em alfanumerico: ");
                        conv_MorseParaAlfaNumerico(entrada);
                        esperar();
                        break;
                }
                break;
            case '3':
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
            case '0':
                clear();
                printf(ROXO"Obrigado por utilizar o nosso conversor, ate breve!\n"FIM_COR);
                break;
            default:
                continue;
                break;
        }
    } while (escolha != '0');

    return 0;
}