#include "Zalgorithm.h"
#include "gtest/gtest.h"

#include <string>

using testing::Test;

// Testing MatchLength calculation when no matches occur
TEST(MatchLengthTest, NoMatchTest) {
    EXPECT_EQ(MatchLength(" assas",1,3),0);
}

// Testing MatchLength calculation when geginning of string matches
TEST(MatchLengthTest, BeginningStringMatch) {
EXPECT_EQ(MatchLength(" assas",1,1),5);
}

// Testing MatchLength calculation when middle of the string matches
TEST(MatchLengthTest, MidStringMatch) {
EXPECT_EQ(MatchLength(" asdasd",1,4),3);
}

// Testing MatchLength calculation when match stops at end of string
TEST(MatchLengthTest, EndOfStringMatch) {
EXPECT_EQ(MatchLength(" asdfgha",1,7),1);
}
// Testing Zalgorithm calculation with string S = " aabcaabxaaz", p.7 Gusfield
TEST(ZalgorithmTest, GusfieldExamplePageSeven) {
std::vector<int> Z;
Zalgorithm(" aabcaabxaaz", &Z);
EXPECT_EQ(3,Z.at(5));
}

TEST(ZalgorithmBasedMatching,randomexample){
std::list<int> matches;
ZalgorithmBasedMatching("aab","baabaa",&matches);
std::list<int>::iterator i = matches.begin();
EXPECT_EQ(*i,2);
}

TEST(ZalgorithmBasedMatchingwithsize,randomexample2){
    std::list<int> matches;
    ZalgorithmBasedMatching(" fznrgkbfetdmqlqbgzotlrzbvqbdqdugcielhwbsbvehtftxnwrqsvouuthpjymnexowvebvtqzg"," xlkrmxhdmqfznrgkbfetdmqlqbgzotlrzbvqbdqdugcielhwbsbvehtftxnwrqsvouuthpjymnexowvebvtqzgqithojhellmsve",&matches);
    EXPECT_GE(matches.size(), 1);
}


int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
