#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> q, q2;
        for (int i = 0; i < m; i++)
        {
            q.insert(i);
        }
        for (int j = 1; j < n; j++)
        {
            q2.clear();
            for (int i : q)
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    if (k >= 0 && k<m && grid[k][j]>grid[i][j - 1])
                    {
                        q2.insert(k);
                    }
                }
            }
            swap(q, q2);
            if (q.empty())
            {
                return j - 1;
            }
        }
        return n - 1;
    }
};