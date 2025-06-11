#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i]) && dp[j] + 1 > dp[i] && groups[j] != groups[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<string> res;
        for (int i = maxIndex; i >= 0; i = prev[i])
        {
            res.emplace_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};