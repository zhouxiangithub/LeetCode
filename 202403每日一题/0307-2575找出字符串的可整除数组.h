#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long cur = 0;
        for (char& c : word)
        {
            cur = (cur * 10 + (c - '0')) % m;
            ans.push_back(cur == 0 ? 1 : 0);
        }
        return ans;
    }
};