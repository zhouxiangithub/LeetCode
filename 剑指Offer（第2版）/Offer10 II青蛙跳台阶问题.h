#pragma once
using namespace std;

class Solution
{
public:
	int numWays(int n)
	{
		if (n < 2)
		{
			return 1;
		}
		int MOD = 1000000007;
		int a = 1, b = 1, sum = 1;
		for (int i = 2; i <= n; i++)
		{
			a = b;
			b = sum;
			sum = (a + b) % MOD;
		}
		return sum;
	}
};