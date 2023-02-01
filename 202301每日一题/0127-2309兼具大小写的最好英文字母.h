#pragma once
using namespace std;
#include <string>
#include <unordered_set>

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ht(s.begin(), s.end());
        for (int i = 25; i >= 0; i--)
        {
            if (ht.count('a' + i) > 0 && ht.count('A' + i) > 0)
            {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};

class Solution {
public:
    string greatestLetter(string s) {
        int lower = 0, upper = 0;
        for (auto c : s)
        {
            if (islower(c))
            {
                lower |= 1 << (c - 'a');
            }
            else
            {
                upper |= 1 << (c - 'A');
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (lower & upper & (1 << i))
            {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};