#pragma once
using namespace std;

class Solution
{
public:
	int cuttingRope(int n)
	{
		if (n <= 3)
		{
			return n - 1;
		}
		int MOD = 1000000007, b = n % 3;
		long ans = 1, x = 3;
		for (int a = n / 3 - 1; a > 0; a /= 2)
		{
			if (a % 2 == 1)
			{
				ans = (ans * x) % MOD;
			}
			x = (x * x) % MOD;
		}
		if (b == 0)
		{
			return ans * 3 % MOD;
		}
		else if (b == 1)
		{
			return ans * 4 % MOD;
		}
		else
		{
			return ans * 3 * 2 % MOD;
		}
	}
};