#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                col[j] += grid[i][j];
            }
        }

        long long res = 0;
        for (int i = 0; i < m; i++) {
            int row = accumulate(grid[i].begin(), grid[i].end(), 0);
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res += (row - 1) * (col[j] - 1);
                }
            }
        }
        return res;
    }
};