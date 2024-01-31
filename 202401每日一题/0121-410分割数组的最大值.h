#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(k + 1, LLONG_MAX));
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= min(i, k); j++)
            {
                for (int t = 0; t < i; t++)
                {
                    f[i][j] = min(f[i][j], max(f[t][j - 1], sum[i] - sum[t]));
                }
            }
        }
        return (int)f[n][k];
    }
};