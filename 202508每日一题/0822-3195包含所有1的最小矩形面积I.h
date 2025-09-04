#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minI = m, maxI = 0;
        int minJ = n, maxJ = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minI = min(minI, i);
                    maxI = max(maxI, i);
                    minJ = min(minJ, j);
                    maxJ = max(maxJ, j);
                }
            }
        }
        return (maxI - minI + 1) * (maxJ - minJ + 1);
    }
};