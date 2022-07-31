#pragma once
using namespace std;
#include <vector>

/*
    m��n�еĶ�ά����չ����һά���飺grid[i][j] ==> i*n+j
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = (i * n + j + k) % (m * n);
                ret[index / n][index % n] = grid[i][j];
            }
        }
        return ret;
    }
};