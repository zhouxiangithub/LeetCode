#pragma once
using namespace std;
#include <vector>
#include <algorithm>

constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        //dp[i][j]表示数组arr1中的前i个元素进行了j次替换后组成严格递增子数组末尾元素的最小值
        vector<vector<int>> dp(n + 1, vector<int>(min(m, n) + 1, INF));
        dp[0][0] = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= min(i, m); j++)
            {
                //如果当前元素大于序列的最后一个元素,不替换
                if (arr1[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = arr1[i - 1];
                }

                //从arr2中找出第一个大于序列的最后一个元素进行替换
                if (j > 0 && dp[i - 1][j - 1] != INF)
                {
                    auto it = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end())
                    {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }

                if (i == n && dp[i][j] != INF)
                {
                    return j;
                }
            }
        }
        return -1;
    }
};