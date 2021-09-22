#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int binarySearch(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}

	int search(vector<int>& nums, int target)
	{
		int ans = 0;
		int index = binarySearch(nums, target);
		if (index == -1)
		{
			return 0;
		}
		for (int i = index; i >= 0; i--)
		{
			if (nums[i] == target)
			{
				ans++;
			}
		}
		for (int j = index + 1; j <= nums.size() - 1; j++)
		{
			if (nums[j] == target)
			{
				ans++;
			}
		}
		return ans;
	}

	//34.在排序数组中查找元素的第一个和最后一个位置
	vector<int> searchRange(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
		{
			return vector<int>{-1, -1};
		}
		int index = binarySearch(nums, target);
		if (index == -1)
		{
			return vector<int>{-1, -1};
		}
		int resL = 0, resR = 0;
		for (int i = index; i >= 0; i--)
		{
			if (nums[i] != target)
			{
				resL = i + 1;
				break;
			}
			if (nums[i] == target && i == 0)
			{
				resL = i;
				break;
			}
		}
		for (int j = index; j <= nums.size() - 1; j++)
		{
			if (nums[j] != target)
			{
				resR = j - 1;
				break;
			}
			if (nums[j] == target && j == nums.size() - 1)
			{
				resR = j;
				break;
			}
		}
		return vector<int>{resL, resR};
	}
};