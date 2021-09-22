#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
	bool isStraight(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int index = 0;
		for (int i = 0; i < 4; i++)
		{
			if (nums[i] == 0)
			{
				index++;
			}
			else if (nums[i] == nums[i + 1])
			{
				return false;
			}
		}
		return nums[4] - nums[index] < 5;
	}
};