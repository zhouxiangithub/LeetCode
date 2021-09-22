#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	//Ë«Ö¸Õë
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int i = 0, j = nums.size() - 1;
		while (i < j)
		{
			int sum = nums[i] + nums[j];
			if (sum < target)
			{
				i++;
			}
			else if (sum > target)
			{
				j--;
			}
			else
			{
				return vector<int>{nums[i], nums[j]};
			}
		}
		return vector<int>{-1};
	}
};