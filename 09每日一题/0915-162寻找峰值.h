#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		int n = nums.size();
		int left = 0, right = n - 1, ans = 0;
		while (left <= right)
		{
			if (n == 1)
			{
				return ans;
			}
			int mid = (right - left) / 2 + left;
			if (mid == 0 && nums[mid] > nums[mid + 1])
			{
				ans = mid;
				break;
			}
			if (mid == n - 1 && nums[mid] > nums[mid - 1])
			{
				ans = mid;
				break;
			}
			if (mid > 0 && mid < (n - 1) && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
			{
				ans = mid;
				break;
			}
			if (nums[mid] < nums[mid + 1])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return ans;
	}
};