#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    dp(x,i,j)表示字符串区间s[i:j]中以字符x为开头结尾的不同回文序列总数
    s[i:j]表示字符串s从下标i到下标j的字串
    特别的，当s[i]=x且s[j]=x，考虑加上xx和x两个单独的回文序列
*/
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i = 0; i < n; i++)
        {
            dp[s[i] - 'a'][i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0, j = len - 1; j < n; i++, j++)
            {
                for (char c = 'a', k = 0; c <= 'd'; c++, k++)
                {
                    if (s[i] == c && s[j] == c)
                    {
                        dp[k][i][j] = (2LL + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD;
                    }
                    else if (s[i] == c)
                    {
                        dp[k][i][j] = dp[k][i][j - 1];
                    }
                    else if (s[j] == c)
                    {
                        dp[k][i][j] = dp[k][i + 1][j];
                    }
                    else
                    {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 4; i++)
        {
            res = (res + dp[i][0][n - 1]) % MOD;
        }
        return res;
    }
};
