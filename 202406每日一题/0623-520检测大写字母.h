#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperWordCnt = 0;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                upperWordCnt++;
            }
        }
        if (isupper(word[0])) {
            return upperWordCnt == word.size() || upperWordCnt == 1;
        }
        else
        {
            return upperWordCnt == 0;
        }
    }
};