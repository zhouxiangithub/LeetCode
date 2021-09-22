#pragma once
using namespace std;
#include <string>

/*2021-09-01*/
class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int m = version1.length(), n = version2.length(), i = 0, j = 0;
		while (i < m || j < n)
		{
			int x = 0;
			for (; i < m && version1[i] != '.'; i++)
			{
				x = x * 10 + version1[i] - '0';
			}
			i++;
			int y = 0;
			for (; j < n && version2[j] != '.'; j++)
			{
				y = y * 10 + version2[j] - '0';
			}
			j++;
			if (x != y)
			{
				return x > y ? 1 : -1;
			}
		}
		return 0;
	}
};