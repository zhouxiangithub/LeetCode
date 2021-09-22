#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/*
	�������������������ֵ��ַ���x��y��
			��ƴ���ַ��� x+y>y+x���� x>y����֮��x<y
			���磺3 30 > 30 3������ 3 > 30�����Ӧ�ý�30����3֮ǰ
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