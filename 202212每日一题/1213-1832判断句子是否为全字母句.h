#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> exist(26);
        for (auto c : sentence)
        {
            exist[c - 'a'] = true;
        }
        for (auto x : exist)
        {
            if (x == 0)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int state = 0;
        for (auto c : sentence)
        {
            state |= 1 << (c - 'a');
        }
        return state == (1 << 26) - 1;
    }
};