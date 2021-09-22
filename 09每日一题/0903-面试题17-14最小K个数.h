#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

/*2021-09-03*/
class Solution
{
public:
	vector<int> smallestK(vector<int>& arr, int k)
	{
		vector<int> ans(k, 0);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; i++)
		{
			ans[i] = arr[i];
		}
		return ans;
	}

	vector<int> smallestK(vector<int>& arr, int k)
	{
		vector<int> ans(k, 0);
		if (k == 0)
		{
			return ans;
		}
		priority_queue<int> q;
		for (int i = 0; i < k; i++)
		{
			q.push(arr[i]);
		}
		for (int i = k; i < arr.size(); i++)
		{
			if (q.top() > arr[i])
			{
				q.pop();
				q.push(arr[i]);
			}
		}
		for (int i = 0; i < k; i++)
		{
			ans[i] = q.top();
			q.pop();
		}
		return ans;
	}
};