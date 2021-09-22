#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int get(int x)
	{
		int res = 0;
		for (; x; x /= 10) 
		{
			res += x % 10;
		}
		return res;
	}

	int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& flag) //注意加上&引用类型符！！！
	{
		int sum = get(i) + get(j);
		if (i >= m || j >= n || sum > k || flag[i][j])
		{
			return 0;
		}
		flag[i][j] = true;
		return 1 + dfs(i + 1, j, m, n, k, flag) + dfs(i, j + 1, m, n, k, flag);
	}

	int movingCount(int m, int n, int k)
	{
		vector<vector<bool>> flag(m, vector<bool>(n, 0));
		return dfs(0, 0, m, n, k, flag);
	}
};