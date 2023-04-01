#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }
                if (j > 0)
                {
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                }
                f[i][j] += grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(2, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            int pos = i % 2;
            for (int j = 0; j < n; j++)
            {
                f[pos][j] = 0;
                if (i > 0)
                {
                    f[pos][j] = max(f[pos][j], f[1 - pos][j]);
                }
                if (j > 0)
                {
                    f[pos][j] = max(f[pos][j], f[pos][j - 1]);
                }
                f[pos][j] += grid[i][j];
            }
        }
        return f[(m - 1) % 2][n - 1];
    }
};