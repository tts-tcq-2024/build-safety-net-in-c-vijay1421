#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


void testGenerateSoundex() {
    char soundex[5];

    generateSoundex("Vijay", soundex);
    assert(strcmp(soundex, "V200") == 0);
    
    generateSoundex("Banana", soundex);
    assert(strcmp(soundex, "B500") == 0);

    generateSoundex("Rules", soundex);
    assert(strcmp(soundex, "R420") == 0);

    generateSoundex("Bee", soundex);
    assert(strcmp(soundex, "B000") == 0);

    generateSoundex("O'Connor", soundex);
    assert(strcmp(soundex, "O256") == 0);

    generateSoundex("AEIOU", soundex);
    assert(strcmp(soundex, "A000") == 0);
}

int main() {
    testGenerateSoundex();
    return 0;
}
