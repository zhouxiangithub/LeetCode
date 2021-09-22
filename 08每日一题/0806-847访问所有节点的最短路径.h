#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <tuple>

/*2021-08-06*/
class Solution
{
	int shortestPathLength(vector<vector<int>>& graph)
	{
		int n = graph.size();
		queue<tuple<int, int, int>> q;
		vector<vector<int>> seen(n, vector<int>(1 << n));
		//初始化
		for (int i = 0; i < n; ++i)
		{
			q.emplace(i, 1 << i, 0);
			seen[i][1 << i] = true;
		}

		int ans = 0;
		while (!q.empty())
		{
			int u = std::get<0>(q.front());
			int mask = std::get<1>(q.front());
			int dist = std::get<2>(q.front());
			q.pop();
			if (mask == (1 << n) - 1)
			{
				ans = dist;
				break;
			}
			//搜索相邻的节点
			for (int v : graph[u])
			{
				int mask_v = mask | (1 << v);
				if (!seen[v][mask_v])
				{
					q.emplace(v, mask_v, dist + 1);
					seen[v][mask_v] = true;
				}
			}
		}
		return ans;
	}
};