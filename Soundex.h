#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char codeTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    if (isalpha(c)) {
        return codeTable[toupper(c) - 'A'];
    }
    return '0';
}

// Function to update the Soundex code array
int updateSoundex(char code, int sIndex, char *soundex) {
    if (code != '0') {
        soundex[sIndex] = code;
        return sIndex + 1;
    }
    return sIndex;
}

// Function to generate the Soundex code from a name
void generateSoundex(const char *name, char *soundex) {
    if (name[0] != '\0') {
        soundex[0] = toupper(name[0]);
    }
    int sIndex = 1;

    for (int i = 1; name[i] != '\0' && sIndex <= 3; ++i) {
        sIndex = updateSoundex(getSoundexCode(name[i]), sIndex, soundex);
    }
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
