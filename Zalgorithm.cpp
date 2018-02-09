#include <list>
#include <string>
#include <vector>

#include "Zalgorithm.h"
#include <string>



// Input: Pattern P, text T, data structure matches to store result
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      T is also 1-indexed
// Output: Indices corresponding to occurrances of P in T
void ZalgorithmBasedMatching(
    const std::string& P,
    const std::string& T,
    std::list<int>* matches) {

    std::vector<int> Z;
    size_t p = P.find(" ");
    std::string newPattern = P;
    if(p == 0)
        newPattern=newPattern.substr(1, newPattern.length());
    size_t t = T.find(" ");
    std::string newText = T;
    if(t == 0)
        newText=newText.substr(1, newText.length());

    Zalgorithm(" "+newPattern+"$"+newText,&Z);
    for (std::vector<int>::const_iterator i = Z.begin(); i != Z.end(); ++i){
        if (*i == newPattern.length()){ //if contents match

            matches->push_back(i-Z.begin()-newPattern.length()-1); //grab location in vector
        }
    }
}

// Input: String S, data structure Z to store result
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: Indices corresponding to occurrances of P in T
void Zalgorithm(const std::string& S, std::vector<int>* Z) {
    int l = 0, r = 0;
    Z->resize(S.length());
    for (int k = 2; k < S.length(); k++) {
        if (k > r) {
            l = k;
            r = k;
            (*Z)[k] = MatchLength(S, 1, r);
            if ((*Z)[k] > 0) {
                l = k;
                r = l + (*Z)[k] - 1;
            }
        } else {

            int zPoint = k - l + 1;
            int rBound = r - k + 1;
            if ((*Z)[zPoint] < rBound) {
                (*Z)[k] = (*Z)[zPoint];
            } else {
                l = k;
                r = MatchLength(S, rBound, r);
                (*Z)[k] = r+rBound-1;
                r++;
            }
        }
    }
    // TODO: Implement this
}

// Input: String S, positions i and j of S
//      S is 1-indexed, so we represent the string "abc" by S = " abc" aab
// Output: length of longest common prefix of S[i, n] and S[j, n] where n = |S|
int MatchLength(const std::string& S, int i, int j) {
    int result = 0;
    std::string templ;
    std::string tempr;

    while (j < S.length() && j < S.length() && S[i]==S[j]){
        templ = S.substr(i,S.length()); //for debugging
        tempr = S.substr(j,S.length()); //for debugging
        i++;
        j++;
        result++;
    }
    //while (j < S.length() && S[j] == S[j - i-1]) {
     //   j++;
     //   result++;
    //}
    return result;
}

/*
int main(int argc, char** argv) {   //for testing
    std::list<int> matches;
    ZalgorithmBasedMatching(" tehx"," edfblmyoltdgecyskmnyklbophvjdnqvnrbmlzpzwbapwqdvegtehxqiamoznopxxrfsqbnvoxdrikrijvbpzamwquoczyitdhus",&matches);
    if(matches.size()==1){
        return 0;
    };
}*/