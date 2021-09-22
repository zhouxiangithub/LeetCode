#pragma once
using namespace std;
#include <vector>

/*
	分析：
	要想得到 i 个 A，我们必须首先拥有 j 个 A，使用一次「复制全部」操作，再使用若干次「粘贴」操作得到 i 个 A。
	因此，这里的 j 必须是 i 的因数，「粘贴」操作的使用次数即为 i/j - 1
*/
class Solution
{
public:
	int minSteps(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		vector<int> f(n + 1);
		for (int i = 2; i <= n; i++)
		{
			f[i] = INT_MAX;
			for (int j = 1; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					f[i] = min(f[i], f[j] + i / j);
					f[i] = min(f[i], f[i / j] + j);
				}
			}
		}
		return f[n];
	}

	int minSteps(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		int ans = 0;
		for (int i = 2; i * i <= n; i++)
		{
			while (n % i == 0)
			{
				n /= i;
				ans += i;
			}
		}
		if (n > 1)
		{
			ans += n;
		}
		return ans;
	}
};