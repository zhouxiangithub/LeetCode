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
		vector<vector<int>> order(n, vector<int>(n)); //����j��i�������б��е��׽��̶��±�
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				order[i][preferences[i][j]] = j;
			}
		}
		vector<int> match(n); //������
		for (const auto& pr : pairs)
		{
			match[pr[0]] = pr[1];
			match[pr[1]] = pr[0];
		}

		/*
			1.�ҵ�������x��Ե�����y
			2.�ҵ�����y������x�������б��е��׽��̶��±꣬��Ϊindex
			3.����x�������б��е��±��0��index-1�����Ѷ��ǿ��ܵ�u������ÿ�����ܵ�u���ҵ�������u��Ե�����v
			4.���order[u][x]<order[u][v]����x�ǲ����ĵ�����
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
