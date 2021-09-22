#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	//枚举+哈希表
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
		1、用二维数组存储各点之间的距离d[i][j]
		2、排序i点到各点的距离d[i]，计算i点到其余各点相同距离的个数cnt
		3、从cnt中有序地选出两个点进行排序，即为组合数：A(cnt,2)
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
			sort(v.begin(), v.end()); //从小到大排序第i个点到其余各点的距离
			int cnt = 1; //cnt统计相同距离的个数
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
			ans += cnt * (cnt - 1); //计算最后一组相同距离的排序个数
		}
		return ans;
	}
};