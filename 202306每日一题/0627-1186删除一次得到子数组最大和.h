#pragma once
using namespace std;
#include <vector>

/*
    dp[i][k]:以arr[i]结尾并删除k次的非空子数组的最大和

    dp[0][0] = arr[0]
    dp[0][1] = 0

    dp[i][0] = max(dp[i-1][0],0) + arr[i]
    dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0])
*/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp0 = arr[0], dp1 = 0, res = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            dp1 = max(dp1 + arr[i], dp0);
            dp0 = max(dp0, 0) + arr[i];
            res = max(res, max(dp1, dp0));
        }
        return res;
    }
};