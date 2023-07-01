#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (equal(row, col, grid))
                {
                    res++;
                }
            }
        }
        return res;
    }

    bool equal(int row, int col, vector<vector<int>>& grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            if (grid[row][i] != grid[i][col])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for (auto row : grid)
        {
            cnt[row]++;
        }
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            vector<int> col;
            for (int i = 0; i < n; i++)
            {
                col.emplace_back(grid[i][j]);
            }
            if (cnt.find(col) != cnt.end())
            {
                res += cnt[col];
            }
        }
        return res;
    }
};