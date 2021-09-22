#pragma once
using namespace std;
#include <vector>

/*
	分析：
		如果已知[l,r]的区间和等于target，那么枚举下一个起点的时候，区间[l+1,r]的和必然小于target；
		我们就不需要再从l+1再开始重复枚举了，而是从r+1开始枚举。
*/
class Solution
{
public:
	vector<vector<int>> findContinuousSequence(int target)
	{
		vector<vector<int>> ans;
		vector<int> tmp;
		for (int l = 1, r = 2; l < r;)
		{
			int sum = (l + r) * (r - l + 1) / 2;
			if (sum == target)
			{
				tmp.clear();
				for (int i = l; i <= r; i++)
				{
					tmp.emplace_back(i);
				}
				ans.emplace_back(tmp);
				l++;
			}
			else if (sum < target)
			{
				r++;
			}
			else
			{
				l++;
			}
		}
		return ans;
	}
};