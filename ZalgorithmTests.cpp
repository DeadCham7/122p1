#include "Zalgorithm.h"
#include "gtest/gtest.h"

#include <string>

using testing::Test;

// Testing MatchLength calculation when no matches occur
TEST(MatchLengthTest, NoMatchTest) {
    bool checker = 1;
    if (MatchLength(const std::string& S, int i, int j) < 1) {
        checker = 0;
    }
    
    EXPECT_EQ(checker,0);
  // TODO: Implement this
}

// Testing MatchLength calculation when geginning of string matches
TEST(MatchLengthTest, BeginningStringMatch) {
    bool checker = 0;
    if (MatchLength(const std::string& S, int i, int j) == 1) {
        checker = 1;
    }
    
    EXPECT_EQ(checker, 1);
  // TODO: Implement this
}

// Testing MatchLength calculation when middle of the string matches
TEST(MatchLengthTest, MidStringMatch) {
    bool checker = 0;
    
    if (S.length() % 2 !=0 && (S.length()/2+1 == MatchLength(const std::string& S, int i, int j))) {
        checker = 1;
    }
    
    EXPECT_EQ(checker, 1);
  // TODO: Implement this
}

// Testing MatchLength calculation when match stops at end of string
TEST(MatchLengthTest, EndOfStringMatch) {
    bool checker = 0;
    
    if (S.length() == MatchLength(const std::string& S, int i, int j)) {
        checker = 1;
    }
    
    EXPECT_EQ(checker, 1);
  // TODO: Implement this
}

// Testing Zalgorithm calculation with string S = " aabcaabxaaz", p.7 Gusfield
TEST(ZalgorithmTest, GusfieldExamplePageSeven) {
    std::list<int>* Z;
    std::string S = " aabcaabxaaz";
    int[] CheckArray = [1,0,0,3,1,0,0,2,2,1,0],
    int count;
    int i = 0;
    bool checker = 0;
    Zalgorithm(S, Z);
    std::list<int>*::iterator it;
    
    for (it = Z.begin(); it != Z.end();it++) {
        if (checkArray[i] == *it) {
            count++;
        }
        i++;
    }
    if (count == Z.length()) {
        checker = 1;
    }
    
    EXPECT_EQ(checker, 1);
  // TODO: Implement this. Check only values given in the text
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
