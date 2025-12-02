#pragma once
using namespace std;
#include <string>
#include <unordered_set>

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int res = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int left = 0, right = n - 1;
            while (left < n && s[left] != ch) {
                left++;
            }
            while (right >= 0 && s[right] != ch) {
                right--;
            }
            if (right - left + 1 <= 2) {
                continue;
            }

            // [left+1, right-1]
            unordered_set<char> uSet;
            for (int i = left + 1; i < right; i++) {
                uSet.insert(s[i]);
            }
            res += uSet.size();
        }
        return res;
    }
};