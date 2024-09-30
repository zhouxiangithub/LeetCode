#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        int cur = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1] - 1) {
                cur++;
            }
            else {
                cur = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};