#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        for (const string& word1 : words1)
        {
            freq1[word1]++;
        }
        for (const string& word2 : words2)
        {
            freq2[word2]++;
        }
        int res = 0;
        for (const auto& [word, cnt] : freq1)
        {
            if (cnt == 1 && freq2[word] == 1)
            {
                res++;
            }
        }
        return res;
    }
};