#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Function to get the Soundex code for a character
char alphabetsToCode(char c) {
    static const char alphabetsCode[26] = {'0', '1', '2', '3','0',  '1',  '2',  '0','0',  '2',  '2', '4','5', '5', '0',  '1', '2', '6','2', '3','0', '1',  '0', '2','0', '2'};

    c = toupper(c);
    if (isalpha(c)) {
        return alphabetsCode[c - 'A'];
    }
    return '0';
}
void initializeSoundex(char *soundex, char firstLetter) {
    soundex[0] = toupper(firstLetter);
}

void handleAlphabets(char currentChar, char *soundex, int *sIndex, char *previousCode) {
    char code = alphabetsToCode(currentChar);
    if (code != '0' && code != *previousCode) {
        soundex[(*sIndex)++] = code;
        *previousCode = code;
    }
}

void processAlphabets(const char *name, char *soundex, int *sIndex, char *previousCode) {
    for (int i = 1; name[i] != '\0' && *sIndex < 4; i++) {
        handleAlphabets(name[i], soundex, sIndex, previousCode);
    }
}

void fillEmptyWithZeroes(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0';
    }
}

void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name[0]);
    char previousCode = alphabetsToCode(name[0]);
    int sIndex = 1;

    processAlphabets(name, soundex, &sIndex, &previousCode);
    fillEmptyWithZeroes(soundex, &sIndex);

    soundex[4] = '\0';
}
#endif
