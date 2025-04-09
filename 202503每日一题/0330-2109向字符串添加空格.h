#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string ans;
        ans.reserve(n + spaces.size());

        int sIdx = 0;
        for (int i = 0; i < n; i++) {
            if (sIdx < spaces.size() && spaces[sIdx] == i) {
                ans.push_back(' ');
                sIdx++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};