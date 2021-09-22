#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	//f(i)�����Ե�i������β��[���������������]����f(i)=max{f(i-1)+nums[i], nums[i]}���󣺵�0<=i<=n-1ʱ��max{f(i)}
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

//�������������[l,r]������
class Solution2
{
public:
	struct Status
	{
		//lSum:[l,r]����lΪ��˵������Ӷκͣ�rSum:[l,r]����rΪ�Ҷ˵������Ӷκͣ�mSum:[l,r]�ڵ�����Ӷκͣ�iSum:[l,r]�������
		int lSum, rSum, mSum, iSum;
	};

	//�߶�������������������������
	Status pushUp(Status l, Status r)
	{
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, r.iSum + l.rSum);
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum); //[l,r]��mSum��Ӧ�������Ƿ��Խm
		return { lSum, rSum, mSum, iSum };
	}

	//��ѯa����[l,r]�����ڵ�����Ӷκ�
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