#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (right - left) / 2 + left;
			int num = nums[mid];
			if (num == target)
			{
				return mid;
			}
			else if (num < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}
};