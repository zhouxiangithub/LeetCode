#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int n = nums.size();
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			if (mp.count(nums[i]) == 0)
			{
				mp[nums[i]] = 1;
			}
			else
			{
				mp[nums[i]] = -1;
			}
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == 1)
			{
				return it->first;
			}
		}
		return -1;
	}

	//ͳ���������ֵĸ�������λ��1�ĳ��ִ���������3���࣬�����Ϊֻ����һ�ε�����
	int singleNumber(vector<int>& nums)
	{
		vector<int> counts(32);
		for (int num : nums)
		{
			for (int j = 0; j < 32; j++)
			{
				counts[j] += num & 1;
				num >>= 1;
			}
		}
		int res = 0, m = 3;
		for (int i = 0; i < 32; i++)
		{
			res <<= 1;
			res |= counts[31 - i] % m;
		}
		return res;
	}
};