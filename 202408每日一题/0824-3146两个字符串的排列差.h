#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> char2Index;
        for (int i = 0; i < s.size(); i++) {
            char2Index[s[i]] = i;
        }
        int res = 0;
        for (int j = 0; j < t.size(); j++) {
            res += abs(j - char2Index[t[j]]);
        }
        return res;
    }
};