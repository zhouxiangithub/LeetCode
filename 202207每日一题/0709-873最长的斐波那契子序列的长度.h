#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

/*
    定义二维数组dp表示以每个下标对的元素作为最后两个数字的斐波那契子序列的最大长度
    当i>j时，dp[j][i]表示以arr[j]和arr[i]作为最后两个数字的斐波那契子序列的最大长度

    arr[k] + arr[j] = arr[i], k<j<i

    当dp[k][j]>=3时，dp[j][i]=dp[k][j]+1
    当dp[k][j]<3时，以arr[k]和arr[j]作为最后两个数字的斐波那契子序列并不存在，
    但是以arr[j]和arr[i]作为最后两个数字的斐波那契子序列存在，此时dp[j][i]=3

    dp[j][i] = max(dp[k][j]+1, 3), 0<=k<j
             = 0, k<0 or k>=j
    
    为了满足k<j即arr[k]<arr[j]，则：arr[i] = arr[k] + arr[j] < 2*arr[j]
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> indices;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            indices[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0 && 2 * arr[j] > arr[i]; j--) // k < j, arr[k] < arr[j]
            {
                int k = -1;
                if (indices.count(arr[i] - arr[j]))
                {
                    k = indices[arr[i] - arr[j]];
                }
                if (k >= 0)
                {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};