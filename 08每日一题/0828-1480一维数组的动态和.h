#pragma once
using namespace std;
#include <vector>

/*2021-08-28*/
class Solution
{
public:
	vector<int> runningSum(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n - 1; i++)
		{
			nums[i + 1] += nums[i];
		}
		return nums;
	}
};