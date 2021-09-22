#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	//f(i)代表以第i个数结尾的[连续子数组的最大和]，则：f(i)=max{f(i-1)+nums[i], nums[i]}，求：当0<=i<=n-1时，max{f(i)}
	int maxSubArray(vector<int>& nums)
	{
		int pre = 0, maxAns = nums[0];
		for (const auto& num : nums)
		{
			pre = max(pre + num, num);
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};

//解决任意子区间[l,r]的问题
class Solution2
{
public:
	struct Status
	{
		//lSum:[l,r]内以l为左端点的最大子段和；rSum:[l,r]内以r为右端点的最大子段和；mSum:[l,r]内的最大子段和；iSum:[l,r]的区间和
		int lSum, rSum, mSum, iSum;
	};

	//线段树求解最长公共上升子序列问题
	Status pushUp(Status l, Status r)
	{
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, r.iSum + l.rSum);
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum); //[l,r]的mSum对应的区间是否跨越m
		return { lSum, rSum, mSum, iSum };
	}

	//查询a序列[l,r]区间内的最大子段和
	Status get(vector<int>& a, int l, int r)
	{
		if (l == r)
		{
			return { a[l], a[l], a[l], a[l] };
		}
		int m = (l + r) >> 1;
		Status lSub = get(a, l, m);
		Status rSub = get(a, m + 1, r);
		return pushUp(lSub, rSub);
	}

	int maxSubArray(vector<int>& nums)
	{
		return get(nums, 0, nums.size() - 1).mSum;
	}
};