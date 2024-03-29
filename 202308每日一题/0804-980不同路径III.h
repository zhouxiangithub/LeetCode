#pragma once
using namespace std;
#include <vector>
#include <functional>
#include <array>

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int si = 0, sj = 0, n = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    n++;
                }
                else if (grid[i][j] == 1)
                {
                    n++;
                    si = i;
                    sj = j;
                }
            }
        }

        //当前状态下从点(i,j)出发还要经过n个点走到终点的路径条数
        function<int(int, int, int)> dfs = [&](int i, int j, int n)->int {
            if (grid[i][j] == 2)
            {
                if (n == 0)
                {
                    return 1;
                }
                return 0;
            }
            int t = grid[i][j], res = 0;
            grid[i][j] = -1;
            vector<array<int, 2>> dir({ {-1,0},{1,0},{0,-1},{0,1} });
            for (auto& [di, dj] : dir)
            {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && (grid[ni][nj] == 0 || grid[ni][nj] == 2))
                {
                    res += dfs(ni, nj, n - 1);
                }
            }
            grid[i][j] = t;
            return res;
        };
        return dfs(si, sj, n);
    }
};