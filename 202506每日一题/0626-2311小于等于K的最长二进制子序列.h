#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0;
        int sum = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.length(); i++) {
            char ch = s[s.length() - 1 - i];
            if (ch == '1') {
                if (i < bits && sum + (1 << i) <= k) {
                    sum += (1 << i);
                    res++;
                }
            }
            else {
                res++;
            }
        }
        return res;
    }
};