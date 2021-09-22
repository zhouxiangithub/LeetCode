#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	//哈希表：键表示一个元素，值表示该元素出现的次数
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> counts;
		int ans = 0, cnt = 0;
		for (int num : nums)
		{
			counts[num]++;
			if (counts[num] > cnt)
			{
				ans = num;
				cnt = counts[num];
			}
		}
		return ans;
	}

	//排序：排序后下标为n/2的元素一定是众数
	int majorityElement(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

};