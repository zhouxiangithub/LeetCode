#pragma once
#include <iostream>
using namespace std;
#include <vector>

/*2021-08-14*/
class Solution
{
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
	{
		vector<vector<int>> order(n, vector<int>(n)); //朋友j在i的朋友列表中的亲近程度下标
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				order[i][preferences[i][j]] = j;
			}
		}
		vector<int> match(n); //配对情况
		for (const auto& pr : pairs)
		{
			match[pr[0]] = pr[1];
			match[pr[1]] = pr[0];
		}

		/*
			1.找到与朋友x配对的朋友y
			2.找到朋友y在朋友x的朋友列表中的亲近程度下标，记为index
			3.朋友x的朋友列表中的下标从0到index-1的朋友都是可能的u。遍历每个可能的u，找到与朋友u配对的朋友v
			4.如果order[u][x]<order[u][v]，则x是不开心的朋友
		*/
		int unhappyCount = 0;
		for (int x = 0; x < n; ++x)
		{
			int y = match[x];
			int index = order[x][y];
			for (int i = 0; i < index; ++i)
			{
				int u = preferences[x][i];
				int v = match[u];
				if (order[u][x] < order[u][v])
				{
					++unhappyCount;
					break;
				}
			}
		}
		return unhappyCount;
	}
};
