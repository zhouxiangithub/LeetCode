#pragma once
using namespace std;
#include <vector>
#include <math.h>
#include <string>

class Solution
{
	vector<int> printNumbers(int n)
	{
		int max = pow(10, n) - 1;
		vector<int> ans(max);
		for (int i = 0; i < max; i++)
		{
			ans[i] = i + 1;
		}
		return ans;
	}

	//´óÊý
	vector<int> res;

	void dfs(int index, string& num, int digit)
	{
		if (index == digit)
		{
			res.emplace_back(atoi(num.c_str()));
			return;
		}
		for (char i = '0'; i <= '9'; i++)
		{
			num.push_back(i);
			dfs(index + 1, num, digit);
			num.pop_back();
		}
	}

	vector<int> printNumbers(int n)
	{
		for (int digit = 1; digit <= n; digit++)
		{
			for (char i = '1'; i <= '9'; i++)
			{
				string num(1, i);
				dfs(1, num, digit);
			}
		}
		return res;
	}
};