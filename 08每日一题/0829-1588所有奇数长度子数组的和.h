#pragma once
using namespace std;
#include <vector>

/*2021-08-29*/
class Solution
{
	//暴力
	int sumOddLengthSubarrays(vector<int>& arr)
	{
		int sum = 0;
		int n = arr.size();
		for (int start = 0; start < n; start++)
		{
			for (int len = 1; start + len <= n; len += 2)
			{
				int end = start + len - 1;
				for (int i = start; i <= end; i++)
				{
					sum += arr[i];
				}
			}
		}
		return sum;
	}

	//前缀和：prefixSum[i]表示数组arr从下标0到下标(i-1)的元素和
	int sumOddLengthSubarrays(vector<int>& arr)
	{
		int n = arr.size();
		vector<int> prefixSum(n + 1);
		for (int i = 0; i < n; i++)
		{
			prefixSum[i + 1] = prefixSum[i] + arr[i];
		}
		int sum = 0;
		for (int start = 0; start < n; start++)
		{
			for (int len = 1; start + len <= n; len += 2)
			{
				int end = start + len - 1;
				sum += prefixSum[end + 1] - prefixSum[start];
			}
		}
		return sum;
	}
};