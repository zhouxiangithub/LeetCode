#pragma once
using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		double ans = 1.0;
		long m = n;
		if (x == 0)
		{
			if (n > 0)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		if (n == 0)
		{
			return 1;
		}
		if (m < 0)
		{
			x = 1 / x;
			m = -m;
		}
		while (m > 0)
		{
			if ((m & 1) == 1)
			{
				ans = ans * x;
			}
			x *= x;
			m >>= 1;
		}
		return ans;
	}
};