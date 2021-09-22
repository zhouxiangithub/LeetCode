#pragma once
using namespace std;
#include <vector>

/*
	������
	Ҫ��õ� i �� A�����Ǳ�������ӵ�� j �� A��ʹ��һ�Ρ�����ȫ������������ʹ�����ɴΡ�ճ���������õ� i �� A��
	��ˣ������ j ������ i ����������ճ����������ʹ�ô�����Ϊ i/j - 1
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