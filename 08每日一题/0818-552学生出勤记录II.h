#pragma once
#include <iostream>
using namespace std;
#include <vector>

/*2021-08-18*/
class Solution
{
public:
	static constexpr int MOD = 1000000007;

	//dp[i][][]的值从dp[i-1][][]的值转移得到，0<=i<=n，0<=j<=1，0<=k<=2
	int checkRecord(int n)
	{
		//长度，A的数量，结尾连续L的数量
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			//第i天的出勤记录是'P'，结尾连续'L'的数量清零
			for (int j = 0; j <= 1; j++)
			{
				for (int k = 0; k <= 2; k++)
				{
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
				}
			}
			//第i天的出勤记录是'A'，结尾连续'L'的数量清零
			for (int k = 0; k <= 2; k++)
			{
				dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
			}
			//第i天的出勤记录是'L'
			for (int j = 0; j <= 1; j++)
			{
				for (int k = 1; k <= 2; k++)
				{
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
				}
			}
		}
		int sum = 0;
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				sum = (sum + dp[n][j][k]) % MOD;
			}
		}
		return sum;
	}
};
