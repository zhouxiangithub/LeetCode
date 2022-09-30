#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length())
        {
            return false;
        }
        vector<int> table(128, 0);
        for (auto& ch : s1)
        {
            table[ch]++;
        }
        for (auto& ch : s2)
        {
            table[ch]--;
            if (table[ch] < 0)
            {
                return false;
            }
        }
        return true;
    }
};