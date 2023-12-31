#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() != words.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (words[i][0] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};