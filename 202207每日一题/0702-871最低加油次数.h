#pragma once
using namespace std;
#include <vector>

/*
    dp[i]表示加油i次的最大行驶英里数

    当遍历到加油站stations[i]时，假设再到达该加油站之前已经加油j次，其中0<=j<=i
    则只有当dp[j]>=stations[i][0]时才能在加油j次的情况下达到加油站stations[i]的位置
    在加油站stations[i]加油之后，共加油j+1次，可以行驶的英里数是dp[j]+stations[i][1]
    遍历满足0<=j<=i且dp[j]>=stations[i][0]的每个下标j，计算dp[j+1]的最大值

    当遍历到加油站stations[i]时，对于每个符合要求的下标j，计算dp[j+1]时都是将加油站stations[i]
    作为最后一次加油的加油站。为了确保每个dp[j+1]的计算中，加油站stations[i]只会被计算一次，
    应该按照从大到小的顺序遍历下标j。
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (dp[j] >= stations[i][0])
                {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (dp[i] >= target)
            {
                return i;
            }
        }
        return -1;
    }
};