#pragma once
using namespace std;
#include <string>
#include <unordered_set>

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> uSet;
        for (char c : s) {
            uSet.insert(c);
        }
        return uSet.size();
    }
};

class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};