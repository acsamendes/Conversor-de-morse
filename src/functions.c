#include "../include/morse.h"

char morse_num[10][6] = {
    "-----",
    ".----",
    "..---",
    "...--",
    "....-", 
    ".....",
    "-....",
    "--...",
    "---..",
    "----."
};



char morse_alpha[27][6] = {//ultima coluna para o \0
    ".-", //a
    "-...", //b
    "-.-.",//c
    "-..",//d
    ".",//e
    "..-.",//f
    "--.",//g
    "....",//h
    "..",//i
    ".---",//j
    "-.-",//k
    ".-..",//l
    "--",//m
    "-.",//n
    "---",//o
    ".--.",//p
    "--.-",//q
    ".-.",//r
    "...",//s
    "-",//t
    "..-",//u
    "...-",//v
    ".--",//w
    "-..-",//x
    "-.--",//y
    "--..",//z
    "/"
    };

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

//função para a conversão de morse para alfanumérico
void conv_MorseParaAlfaNumerico(char *morse){
    // funçao strtok divide a string original (morse) em substrings (caracteres individuais) separadas por espaços
    char *caractere = strtok((char *)morse, " ");

    // loop principal que percorre toda a string original
    int i;
    int encontrado;
    while (caractere != NULL){
        encontrado = 0;
        // loop que compara linearmente cada caractere da substring com a referencia (alfabeto) e realiza a conversão
        for (i = 0; i < 27; i++) {
            if (strcmp(caractere, morse_alpha[i]) == 0) {
                if (i == 26) {//se morse_alpha[i] é a barra que indica espaço
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

        // loop que compara linearmente cada caractere da substring com a referencia (numeros) e realiza a conversão
        for (i = 0; i < 10; i++) {
            if (strcmp(caractere, morse_num[i]) == 0) {
                printf("%d", i);
                encontrado = 1;
                break;
            }
        }

        // imprime um símbolo caso o caractere não tenha sido reconhecido em nenhuma das duas strings bases (alfabeto e numeros)
        if (!encontrado) {
            printf("(?)");
        }

        // relização da passagem para o proximo caractere 
        caractere = strtok(NULL, " ");
    }
}

//funções de conversão de alfanumérico para morse
void toLower(char **string_ref, int tam){//string minuscula
    int i;
    char c;

    char* string = *string_ref;

    for(i=0; i<tam; i++){
        c = string[i];
        if(c>='A' && c<='Z') string[i]= c + 32;
    }

}

char* morse_sourse(char c){
    if(c >= '0' && c <= '9') return morse_num[c - '0'];
    else if(c == ' ') printf(" ");
    return morse_alpha[c-'a'];
}

void xerife(char *id_morse_alpha){
    printf("%s ", id_morse_alpha);
}

void conv_AlfaNumericoToMorse(char *string){    
    int tam = strlen(string);
    toLower(&string, tam);

    for(int i = 0; i<tam; i++){
        xerife(morse_sourse(string[i]));
    }

    printf("\n");

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
    printf(ROXO"\t\t========= CONVERSOR MORSE =========\n\n");
    printf("1 - "FIM_COR);
    printf("Alfanumerico para Morse\n");
    printf(ROXO"2 - "FIM_COR);
    printf("Morse para Alfanumerico\n");
    printf(ROXO"3 - "FIM_COR);
    printf("Como funciona o codigo morse?\n");
    printf(ROXO"0 - "FIM_COR);
    printf("Sair\n");
}

//função esperar para que o usuário pressione enter(interface)
void esperar() {
    printf(ROXO"\nPressione Enter para continuar..."FIM_COR);
    while (getchar() != '\n');
    getchar();  
}

// essa função limpa o buffer, para evitar problemas com o scanf
void limparBuffer() {
    while (getchar() != '\n');
}