#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> res(2);
        for (int i = 0; i < str.length(); i++) {
            res[str[i] - '0']++;
        }
        return res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < strs.size(); i++) {
            vector<int> zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};