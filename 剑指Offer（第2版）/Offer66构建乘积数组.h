#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	vector<int> constructArr(vector<int>& a)
	{
		int n = a.size();
		if (n == 0)
		{
			return vector<int>{};
		}
		vector<int> ans(n, 1);
		ans[0] = 1;
		int tmp = 1;
		for (int i = 1; i < n; i++)
		{
			ans[i] = ans[i - 1] * a[i - 1];
		}
		for (int i = n - 2; i >= 0; i--)
		{
			tmp *= a[i + 1];
			ans[i] *= tmp;
		}
		return ans;
	}
};