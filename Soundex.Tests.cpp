#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


void testGenerateSoundex() {
    char soundex[5];

    // Test case 1: name
    generateSoundex("Vijay", soundex);
    assert(strcmp(soundex, "V200") == 0);

    // Test case 2: Name with repeated leyters
    generateSoundex("Banana", soundex);
    assert(strcmp(soundex, "B500") == 0);

    // Test case 3: Name with mixed vowels and consonants
    generateSoundex("Rules", soundex);
    assert(strcmp(soundex, "R420") == 0);

    // Test case 4: Short name
    generateSoundex("Bee", soundex);
    assert(strcmp(soundex, "B000") == 0);

    printf("All test cases passed successfully!\n");

    // Test case 5: Name with non-alphabetic characters
    generateSoundex("O'Connor", soundex);
    assert(strcmp(soundex, "O256") == 0);

    // Test case 6: Name with all vowels
    generateSoundex("AEIOU", soundex);
    assert(strcmp(soundex, "A000") == 0);
}

int main() {
    testGenerateSoundex();
    return 0;
}
