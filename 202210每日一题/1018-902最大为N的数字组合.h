#pragma once
using namespace std;
#include <vector>
#include <string>

/*
    dp[i][0]表示由digits构成的数小于n的前i位的个数
    dp[i][1]表示由digits构成的数等于n的前i位的个数
*/
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int m = digits.size(), k = s.size();
        vector<vector<int>> dp(k + 1, vector<int>(2));
        dp[0][1] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (digits[j][0] == s[i - 1])
                {
                    dp[i][1] = dp[i - 1][1];
                }
                else if (digits[j][0] < s[i - 1])
                {
                    dp[i][0] += dp[i - 1][1];
                }
                else
                {
                    break;
                }
            }
            if (i > 1)
            {
                dp[i][0] += m + dp[i - 1][0] * m;
            }
        }
        return dp[k][0] + dp[k][1];
    }
};