#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 ASSERT_EQ(soundex,"A200");

 char soundex[5];
generateSoundex("Vijay", soundex);
ASSERT_STREQ(soundex,"V000");
}
