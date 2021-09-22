#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == mid)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left;
	}

	int missingNumber(vector<int>& nums)
	{
		int n = nums.size();
		if (nums[0] == 1)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			if (nums[i] != i)
			{
				return i;
			}
		}
		return n;
	}
};