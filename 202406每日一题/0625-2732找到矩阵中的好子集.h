#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++) {
            int st = 0;
            for (int j = 0; j < n; j++) {
                st |= (grid[i][j] << j);
            }
            mp[st] = i;
        }

        if (mp.count(0)) {
            ans.push_back(mp[0]);
            return ans;
        }

        for (auto [x, i] : mp) {
            for (auto [y, j] : mp) {
                if (!(x & y)) {
                    return { min(i,j),max(i,j) };
                }
            }
        }

        return ans;
    }
};