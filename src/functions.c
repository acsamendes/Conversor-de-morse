#include "../include/morse.h"

// morseAudio: recebe uma string contendo um codigo morse
// e o reproduz em formato de audio
void morseAudio(char *morse) {
    int tam;
    for (int i = 0; i < strlen(morse); i++) {
        if (morse[i] == ' ') {
            _sleep(3000);
        } else if (morse[i] == '-') {
            tam = 2000;
        } else {
            tam = 1000;
        }

        while (tam--) {
            printf("%c", 7);
        }

        _sleep(1000);
    }
}