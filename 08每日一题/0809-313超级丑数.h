#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <queue>

/*2021-08-09*/
class Solution
{
public:
	//最小堆：超出时间限制
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		unordered_set<long> seen;
		priority_queue<long, vector<long>, greater<long>> heap;
		seen.insert(1);
		heap.push(1);
		int ugly = 0;
		for (int i = 0; i < n; i++)
		{
			long curr = heap.top();
			heap.pop();
			ugly = (int)curr;
			for (int prime : primes)
			{
				long next = curr * prime;
				if (seen.insert(next).second)
				{
					heap.push(next);
				}
			}
		}
		return ugly;
	}

	//最小堆：超出时间限制
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(1);
		int ans = 0;
		while (n > 0)
		{
			int cur = pq.top();
			pq.pop();
			if (ans == cur)
			{
				continue;
			}
			ans = cur;
			for (auto& prime : primes)
			{
				if (cur <= INT_MAX / prime)
				{
					pq.push(ans * prime); //在优先队列里加入了很多不必要的元素
				}
				else
				{
					break;
				}
			}
			n--;
		}
		return ans;
	}

	//动态规划（dp[i]表示第i个超级丑数）：超出时间限制
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		vector<int> dp(n + 1);
		dp[1] = 1;
		int m = primes.size();
		vector<int> pointers(m, 1);
		for (int i = 2; i <= n; i++)
		{
			vector<int> nums(m);
			int minNum = INT_MAX;
			for (int j = 0; j < m; j++)
			{
				nums[j] = dp[pointers[j]] * primes[j];
				minNum = min(minNum, nums[j]);
			}
			dp[i] = minNum;
			for (int j = 0; j < m; j++)
			{
				if (minNum == nums[j])
				{
					pointers[j]++;
				}
			}
		}
		return dp[n];
	}

	//动态规划：超出时间限制
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		vector<int> dp;
		vector<int> pointers(primes.size());
		dp.push_back(1);
		while (n > 1)
		{
			n--;
			long minNum = LONG_MAX;
			vector<long> tmp(primes.size());
			for (int i = 0; i < pointers.size(); i++)
			{
				long num = dp[pointers[i]] * primes[i];
				tmp[i] = num;
				minNum = min(minNum, num);
			}
			dp.push_back(minNum);
			for (int i = 0; i < pointers.size(); i++)
			{
				if (tmp[i] == minNum)
				{
					pointers[i]++;
				}
			}
		}
		return dp.back();
	}
};
