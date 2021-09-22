#pragma once
using namespace std;
#include <vector>

/*
	分析：
	由于新增骰子的点数只可能为1至6，因此概率 f(n-1,x) 
	仅与 f(n,x+1), f(n,x+2), ... , f(n,x+6)相关。
	因而，遍历f(n-1)中各点数和的概率，并将其相加至f(n)中所有相关项，
	即可完成f(n-1)至f(n)的递推。

*/
class Solution
{
public:
	vector<double> dicesProbability(int n)
	{
		vector<double> dp(6, 1.0 / 6.0);
		for (int i = 2; i <= n; i++)
		{
			//i个骰子的值范围为：[i, 6*i]，共：6*i-i+1=5*i+1个值
			vector<double> tmp(5 * i + 1, 0);
			for (int j = 0; j < dp.size(); j++)
			{
				for (int k = 0; k < 6; k++)
				{
					tmp[j + k] += dp[j] / 6.0;
				}
			}
			dp = tmp;
		}
		return dp;
	}
};