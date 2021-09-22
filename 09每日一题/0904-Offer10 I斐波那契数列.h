#pragma once
using namespace std;

class Solution
{
public:
	int fib(int n)
	{
		int MOD = 1000000007;
		if (n < 2)
		{
			return n;
		}
		int a = 0, b = 0, sum = 1;
		for (int i = 2; i <= n; i++)
		{
			a = b;
			b = sum;
			sum = (a + b) % MOD;
		}
		return sum;
	}
};