#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        unordered_set<int> banned;
        for (auto&& vec : mines)
        {
            banned.emplace(vec[0] * n + vec[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            //left
            for (int j = 0; j < n; j++)
            {
                if (banned.count(i * n + j))
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            //right
            for (int j = n - 1; j >= 0; j--)
            {
                if (banned.count(i * n + j))
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            //up
            for (int j = 0; j < n; j++)
            {
                if (banned.count(i + j * n))
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
            }
            count = 0;
            //down
            for (int j = n - 1; j >= 0; j--)
            {
                if (banned.count(i + j * n))
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};