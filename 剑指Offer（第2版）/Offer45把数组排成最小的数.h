#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/*
	分析：对于任意两数字的字符串x和y：
			若拼接字符串 x+y>y+x，则 x>y；反之，x<y
			例如：3 30 > 30 3，于是 3 > 30，因此应该将30排在3之前
*/
class Solution
{
public:
	void quickSort(vector<string>& strs, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int i = l, j = r;
		while (i < j)
		{
			while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
			{
				j--;
			}
			while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
			{
				i++;
			}
			swap(strs[i], strs[j]);
		}
		swap(strs[i], strs[l]);
		quickSort(strs, l, i - 1);
		quickSort(strs, i + 1, r);
	}

	string minNumber(vector<int>& nums)
	{
		vector<string> strs;
		for (int i = 0; i < nums.size(); i++)
		{
			strs.emplace_back(to_string(nums[i]));
		}
		//sort(strs.begin(), strs.end(), [](string& x, string& y) {return x + y < y + x; });
		quickSort(strs, 0, strs.size() - 1);
		string res;
		for (string s : strs)
		{
			res.append(s);
		}
		return res;
	}
};