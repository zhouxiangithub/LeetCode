#pragma once
using namespace std;
#include <vector>
#include <array>

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
        {
            return false;
        }
        int n = grid.size();
        vector<array<int, 2>> index(n * n);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                index[grid[i][j]] = { i, j };
            }
        }
        for (int i = 1; i < index.size(); i++)
        {
            int dx = abs(index[i][0] - index[i - 1][0]);
            int dy = abs(index[i][1] - index[i - 1][1]);
            if (dx * dy != 2)
            {
                return false;
            }
        }
        return true;
    }
};