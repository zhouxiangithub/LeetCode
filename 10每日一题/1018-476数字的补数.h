#pragma once
using namespace std;
#include <math.h>

class Solution
{
public:
	int findComplement(int num)
	{
		int i = 0, a[32], sum = 0;
		while (num)
		{
			a[i] = num % 2;
			num /= 2;
			i++;
		}
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] == 0)
			{
				sum += pow(2, j);
			}
		}
		return sum;
	}
};