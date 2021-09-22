#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	int strToInt(string str)
	{
		int res = 0, bndry = INT_MAX / 10; // 2147483647
		int i = 0, sign = 1, len = str.size();
		if (len == 0)
		{
			return 0;
		}
		while (str[i] == ' ')
		{
			if (++i == len)
			{
				return 0;
			}
		}
		if (str[i] == '-')
		{
			sign = -1;
		}
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
		}
		for (int j = i; j < len; j++)
		{
			if (str[j] < '0' || str[j]>'9')
			{
				break;
			}
			if (res > bndry || res == bndry && str[j] > '7')
			{
				return sign == 1 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + (str[j] - '0');
		}
		return sign * res;
	}
};