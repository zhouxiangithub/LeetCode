#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }
        bool hasVowel = false, hasConsonant = false;
        for (auto c : word) {
            if (!isalnum(c)) {
                return false;
            }
            else if (isalpha(c)) {
                c = towlower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    hasVowel = true;
                }
                else {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};