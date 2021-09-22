#pragma once
#include <iostream>
using namespace std;
#include <vector>

/*2021-08-18*/
class Solution
{
public:
	static constexpr int MOD = 1000000007;

	//dp[i][][]��ֵ��dp[i-1][][]��ֵת�Ƶõ���0<=i<=n��0<=j<=1��0<=k<=2
	int checkRecord(int n)
	{
		//���ȣ�A����������β����L������
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			//��i��ĳ��ڼ�¼��'P'����β����'L'����������
			for (int j = 0; j <= 1; j++)
			{
				for (int k = 0; k <= 2; k++)
				{
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
				}
			}
			//��i��ĳ��ڼ�¼��'A'����β����'L'����������
			for (int k = 0; k <= 2; k++)
			{
				dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
			}
			//��i��ĳ��ڼ�¼��'L'
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
