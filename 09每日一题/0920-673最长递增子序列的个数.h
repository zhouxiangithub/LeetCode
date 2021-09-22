#pragma once
using namespace std;
#include <vector>

/*
	分析：
		dp[i]表示以nums[i]结尾的最长上升子序列的长度，cnt[i]表示以nums[i]结尾的最长上升子序列的个数。
*/
class Solution
{
public:
	int findNumberOfLIS(vector<int>& nums)
	{
		int n = nums.size(), maxLen = 0, ans = 0;
		vector<int> dp(n), cnt(n);
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			cnt[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					if (dp[i] < dp[j] + 1)
					{
						dp[i] = dp[j] + 1;
						cnt[i] = cnt[j];
					}
					else if (dp[i] == dp[j] + 1)
					{
						cnt[i] += cnt[j];
					}
				}
			}
			if (dp[i] > maxLen)
			{
				maxLen = dp[i];
				ans = cnt[i];
			}
			else if (dp[i] == maxLen)
			{
				ans += cnt[i];
			}
		}
		return ans;
	}
};