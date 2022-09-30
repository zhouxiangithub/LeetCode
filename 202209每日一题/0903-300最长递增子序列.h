#pragma once
using namespace std;
#include <vector>
#include <algorithm>

//动态规划：dp[i]表示前i个元素中以第i个数字结尾的最长上升子序列的长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//贪心+二分查找：d[i]表示长度为i的最长上升子序列的末尾元素的最小值
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > d[len])
            {
                d[++len] = nums[i];
            }
            else
            {
                int l = 1, r = len, pos = 0;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i])
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};