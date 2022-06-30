#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len)
    {
        if (index == matchsticks.size())
        {
            return true;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len))
            {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0)
        {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};

/*
    按照顺序依次将火柴放入正方形的四条边，只有前一条边放满后，才能将火柴放入后一条边。
    用状态s记录哪些火柴已经放入（s的第k位为1表示第k根火柴已经被放入）
    dp[s]表示正方形未放满的边的当前长度：
        如果去掉它的第k根火柴得到的状态s1满足dp[s1]>=0且dp[s1]+matchsticks[k]<=len
        那么dp[s]=(dp[s1]+matchsticks[k]) mod len
*/
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0)
        {
            return false;
        }
        int len = totalLen / 4, n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((s & (1 << k)) == 0)
                {
                    continue;
                }
                int s1 = s & ~(1 << k); //去掉第k根火柴
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len)
                {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};