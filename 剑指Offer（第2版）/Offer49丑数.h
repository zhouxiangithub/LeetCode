#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int nthUglyNumber(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		vector<int> dp(n);
		dp[0] = 1;
		int id2 = 0, id3 = 0, id5 = 0;
		for (int i = 1; i < n; i++)
		{
			dp[i] = min(dp[id2] * 2, min(dp[id3] * 3, dp[id5] * 5));
			if (dp[id2] * 2 == dp[i])
			{
				id2 += 1;
			}
			if (dp[id3] * 3 == dp[i])
			{
				id3 += 1;
			}
			if (dp[id5] * 5 == dp[i])
			{
				id5 += 1;
			}
		}
		return dp[n - 1];
	}
};