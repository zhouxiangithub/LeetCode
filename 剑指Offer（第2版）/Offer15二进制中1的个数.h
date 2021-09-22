#pragma once
using namespace std;
#include <stdint.h>

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n & (1 << i)) // n & 2^i
			{
				ans++;
			}
		}
		return ans;
	}

	int hammingWeight(uint32_t n)
	{
		int ans = 0;
		while (n)
		{
			n &= (n - 1); //µÖÏûµô×îÓÒ±ßµÄ1
			ans++;
		}
		return ans;
	}
};