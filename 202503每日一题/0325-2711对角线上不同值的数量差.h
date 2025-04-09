#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> sBottomRight;
                int x = i + 1, y = j + 1;
                while (x < m && y < n) {
                    sBottomRight.insert(grid[x][y]);
                    x += 1;
                    y += 1;
                }
                unordered_set<int> sTopLeft;
                x = i - 1, y = j - 1;
                while (x >= 0 && y >= 0) {
                    sTopLeft.insert(grid[x][y]);
                    x -= 1;
                    y -= 1;
                }
                res[i][j] = abs((int)sBottomRight.size() - (int)sTopLeft.size());
            }
        }
        return res;
    }
};