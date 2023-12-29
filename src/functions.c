#include "../include/morse.h"

// morseAudio: recebe uma string contendo um codigo morse
// e o reproduz em formato de audio
void morseAudio(char *morse) {
    int tam;
    for (int i = 0; i < strlen(morse); i++) {
        if (morse[i] == ' ') {
            sleep(2);
        } else if (morse[i] == '-') {
            tam = 2000;
        } else {
            tam = 1000;
        }

        #ifdef __linux__
            while (tam--) {
                printf("\a");
            }
        #elif _WIN32
            BEEP(800, tam);
        #endif

        sleep(1);
        tam = 0;
    }
}