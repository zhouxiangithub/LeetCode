#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	//��ϣ������ʾһ��Ԫ�أ�ֵ��ʾ��Ԫ�س��ֵĴ���
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

	//����������±�Ϊn/2��Ԫ��һ��������
	int majorityElement(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

};