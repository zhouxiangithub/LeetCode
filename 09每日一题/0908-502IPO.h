#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
	分析：
		每次进行选择时，应该从所有投入资本小于等于 w 的项目中选择利润最大的项目 j
*/
class Solution
{
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
	{
		int n = profits.size();
		vector<pair<int, int>> arr;
		priority_queue<int, vector<int>> pq; //默认大根堆
		int index = 0;

		for (int i = 0; i < n; i++)
		{
			arr.emplace_back(make_pair(capital[i], profits[i])); // (资本,利润)
		}
		sort(arr.begin(), arr.end()); //按资本从小到大排序

		for (int i = 0; i < k; i++)
		{
			while (index < n && arr[index].first <= w)
			{
				pq.push(arr[index].second);
				index++;
			}
			if (!pq.empty())
			{
				w += pq.top();
				pq.pop();
			}
			else
			{
				break;
			}
		}

		return w;
	}
};