#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int getLen(int n)
	{
		for (int i = 31; i >= 0; i--)
		{
			if ((n >> i) & 1)
			{
				return i + 1;
			}
		}
		return 0;
	}

	int findIntegers(int n)
	{
		int N = 32;
		// f[i][j] 表示n的二进制表示长度为 i+1 且最高位为 j 时的合法数的个数
		vector<vector<int>> f(N, vector<int>(N, 0));
		f[0][0] = 1;
		f[0][1] = 1;
		for (int i = 1; i < N; i++)
		{
			f[i][0] = f[i - 1][0] + f[i - 1][1];
			f[i][1] = f[i - 1][0];
		}

		int len = getLen(n);
		int ans = 0, pre = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			int cur = ((n >> i) & 1); //当前位
			if (cur == 1)
			{
				ans += f[i][0];
				if (pre == 1)
				{
					break;
				}
			}
			pre = cur;
			if (i == 0)
			{
				ans++;
			}
		}

		return ans;
	}
};