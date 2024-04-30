#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j] = max(res[j], (int)to_string(grid[i][j]).size());
            }
        }
        return res;
    }
};