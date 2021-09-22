#pragma once
using namespace std;

class Solution
{
public:
	int f(int n, int m)
	{
		if (n == 1)
		{
			return 0;
		}
		return (f(n - 1, m) + m % n) % n;
	}

	int lastRemaining(int n, int m)
	{
		return f(n, m);
	}

	int lastRemaining(int n, int m)
	{
		int f = 0;
		for (int i = 2; i != n + 1; i++)
		{
			f = (f + m) % i;
		}
		return f;
	}
};