#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> mp(26, false);
        for (char c : s)
        {
            if (mp[c - 'a'])
            {
                return c;
            }
            mp[c - 'a'] = true;
        }
        return 0;
    }
};

class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (char c : s)
        {
            int t = 1 << (c - 'a');
            if (mask & t)
            {
                return c;
            }
            mask |= t;
        }
        return 0;
    }
};