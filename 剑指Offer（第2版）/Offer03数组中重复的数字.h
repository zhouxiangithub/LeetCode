#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution
{
public:
	int findRepeatNumber(vector<int>& nums)
	{
		map<int, int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (res.count(nums[i]) == 0)
			{
				res[nums[i]] = nums[i];
			}
			else
			{
				return nums[i];
			}
		}
		return -1;
	}

	int findRepeatNumber(vector<int>& nums)
	{
		int i = 0;
		while (i < nums.size())
		{
			if (nums[i] == i)
			{
				i++;
				continue;
			}
			if (nums[nums[i]] == nums[i])
			{
				return nums[i];
			}
			swap(nums[i], nums[nums[i]]);
		}
		return -1;
	}
};