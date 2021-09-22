#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	//ö��+��ϣ��
	int numberOfBoomerangs(vector<vector<int>>& points)
	{
		int ans = 0;
		for (auto& p : points)
		{
			unordered_map<int, int> cnt;
			for (auto& q : points)
			{
				int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
				cnt[dis]++;
			}
			for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
			{
				ans += it->second * (it->second - 1);
			}
		}
		return ans;
	}

	/*
		1���ö�ά����洢����֮��ľ���d[i][j]
		2������i�㵽����ľ���d[i]������i�㵽���������ͬ����ĸ���cnt
		3����cnt�������ѡ��������������򣬼�Ϊ�������A(cnt,2)
	*/
	int numberOfBoomerangs(vector<vector<int>>& points)
	{
		int ans = 0, n = points.size();
		vector<vector<int>> d(n);
		for (int i = 0; i < n - 1; i++)
		{
			auto& p = points[i];
			for (int j = i + 1; j < n; j++)
			{
				auto& q = points[j];
				int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
				d[i].emplace_back(dis);
				d[j].emplace_back(dis);
			}
		}
		for (auto& v : d)
		{
			sort(v.begin(), v.end()); //��С���������i���㵽�������ľ���
			int cnt = 1; //cntͳ����ͬ����ĸ���
			for (int i = 0; i < n - 2; i++)
			{
				if (v[i] != v[i + 1])
				{
					ans += cnt * (cnt - 1);
					cnt = 1;
				}
				else
				{
					cnt++;
				}
			}
			ans += cnt * (cnt - 1); //�������һ����ͬ������������
		}
		return ans;
	}
};