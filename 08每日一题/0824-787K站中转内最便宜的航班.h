#pragma once
using namespace std;
#include <vector>

/*2021-08-24*/
class Solution
{
private:
	static constexpr int INF = 10000 * 101 + 1;
public:
	//经过k站<==>通过(k+1)次航班
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
	{
		//f[t][i]表示通过恰好t次航班，从出发城市src到达城市i需要的最小花费
		//状态转移：f[t][i]=min{f[t-1][j]+cost(j,i)}, (j,i)-->flights
		//求：min{f[1][dst], f[2][dst], ..., f[k+1][dst]}
		vector<vector<int>> f(k + 2, vector<int>(n, INF));
		f[0][src] = 0;
		for (int t = 1; t <= k + 1; t++)
		{
			for (auto&& flight : flights)
			{
				int j = flight[0], i = flight[1], cost = flight[2];
				f[t][i] = min(f[t][i], f[t - 1][j] + cost);
			}
		}
		int ans = INF;
		for (int t = 1; t <= k + 1; t++)
		{
			ans = min(ans, f[t][dst]);
		}
		return (ans == INF ? -1 : ans);
	}
};