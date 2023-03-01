#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //dp[i][m]表示前i堆石头已经被取走,当前的M=m时,接下来取石头的玩家可以比另一方多取的石头数
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
        for (int i = n; i >= 0; i--)
        {
            for (int m = 1; m <= n; m++)
            {
                if (i == n) //前n堆石头都取走了,所以当前玩家可以比另一方多取的石头数为0
                {
                    dp[i][m] = 0;
                }
                else
                {
                    int sum = 0;
                    for (int x = 1; x <= 2 * m; x++) //取剩下的前x堆
                    {
                        if (i + x > n)
                        {
                            break;
                        }
                        sum += piles[i + x - 1]; //取剩下的前x堆的石头数
                        dp[i][m] = max(dp[i][m], sum - dp[i + x][min(n, max(m, x))]);
                    }
                }
            }
        }
        //刚开局(m=1),Alice先开始,所以比Bob多拿的石头数为dp[0][1]
        return (dp[0][1] + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};