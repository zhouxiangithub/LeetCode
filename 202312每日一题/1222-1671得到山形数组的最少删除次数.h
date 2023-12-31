#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> getLISArray(const vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n), seq;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end())
            {
                seq.emplace_back(nums[i]);
                dp[i] = seq.size();
            }
            else
            {
                *it = nums[i];
                dp[i] = it - seq.begin() + 1;
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = getLISArray(nums);
        vector<int> suf = getLISArray({ nums.rbegin(),nums.rend() });
        reverse(suf.begin(), suf.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (pre[i] > 1 && suf[i] > 1)
            {
                ans = max(ans, pre[i] + suf[i] - 1);
            }
        }

        return n - ans;
    }

    vector<int> getLISArray2(const vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
};