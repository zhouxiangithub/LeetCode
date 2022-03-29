#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <stack>

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> hashMap;
		stack<int> stack;
		for (int i = nums2.size() - 1; i >= 0; i--)
		{
			int num = nums2[i];
			while (!stack.empty() && num >= stack.top())
			{
				stack.pop();
			}
			hashMap[num] = stack.empty() ? -1 : stack.top();
			stack.push(num);
		}
		vector<int> res(nums1.size());
		for (int i = 0; i < nums1.size(); i++)
		{
			res[i] = hashMap[nums1[i]];
		}
		return res;
	}
};