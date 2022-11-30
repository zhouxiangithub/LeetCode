#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (auto c : allowed)
        {
            mask |= 1 << (c - 'a');
        }
        int res = 0;
        for (auto&& word : words)
        {
            int submask = 0;
            for (auto c : word)
            {
                submask |= 1 << (c - 'a');
            }
            if ((submask | mask) == mask)
            {
                res++;
            }
        }
        return res;
    }
};