#pragma once
using namespace std;

class Solution
{
public:
	int translateNum(int num)
	{
		if (num <= 9)
		{
			return 1;
		}
		int rem = num % 100;
		if (rem >= 10 && rem <= 25)
		{
			return translateNum(num / 10) + translateNum(num / 100); //当数字xi-1xi可被翻译时
		}
		else
		{
			return translateNum(num / 10); //当数字xi-1xi不可被翻译时
		}
	}

	int translateNum(int num)
	{
		int a = 1, b = 1, x = 0, y = num % 10;
		while (num != 0)
		{
			num /= 10;
			x = num % 10;
			int tmp = 10 * x + y;
			int c = (tmp >= 10 && tmp <= 25) ? a + b : a;
			b = a;
			a = c;
			y = x;
		}
		return a;
	}
};