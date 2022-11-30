#pragma once
using namespace std;
#include <vector>

/*
    dp[i][j]��ʾnums������[0,i-1]���зֳ�j������������ƽ��ֵ��,i>=j

    ��j>1ʱ,������[0,i-1]�ֳ�[0,x-1],[x,i-1]������
    ����:x-1-0+1>=j-1,��:x>=j-1
    ��:dp[i][j]=dp[x][j-1]+(prefix[i]-prefix[x])/(i-x)
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        //j=1
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = prefix[i] / i;
        }
        //j>1
        for (int j = 2; j <= k; j++)
        {
            for (int i = j; i <= n; i++)
            {
                for (int x = j - 1; x < i; x++)
                {
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};