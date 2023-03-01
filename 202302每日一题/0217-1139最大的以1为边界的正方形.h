#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m + 1, vector<int>(n + 1)); //左边1的数量
        vector<vector<int>> up(m + 1, vector<int>(n + 1)); //上面1的数量
        int maxBorder = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (grid[i - 1][j - 1] == 1) //(i,j)右下
                {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int border = min(left[i][j], up[i][j]);
                    //(i-border+1,j)右上,(i,j-border+1)左下
                    while (left[i - border + 1][j] < border || up[i][j - border + 1] < border)
                    {
                        border--;
                    }
                    maxBorder = max(maxBorder, border);
                }
            }
        }
        return maxBorder * maxBorder;
    }
};