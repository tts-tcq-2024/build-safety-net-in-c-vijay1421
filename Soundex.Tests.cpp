#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


void testGenerateSoundex() {
    char soundex[5];
   // test for checking name
    generateSoundex("Vijay", soundex);
    assert(strcmp(soundex, "V200") == 0);
    // test for checking repeated chareters
    generateSoundex("Banana", soundex);
    assert(strcmp(soundex, "B500") == 0);
    // test for repeated vowels
    generateSoundex("Bee", soundex);
    assert(strcmp(soundex, "B000") == 0);

    printf("All test cases passed successfully!\n");

    // test for name with non-alphabetic characters
    generateSoundex("O'Connor", soundex);
    assert(strcmp(soundex, "O256") == 0);

    // test for all vowels
    generateSoundex("AEIOU", soundex);
    assert(strcmp(soundex, "A000") == 0);

}

int main() {
    testGenerateSoundex();
    return 0;
}
