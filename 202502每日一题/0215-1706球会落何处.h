#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; j++) {
            int col = j;
            for (auto& row : grid) {
                int dir = row[col]; // 当前列的值
                col += dir; // 相邻列
                if (col < 0 || col >= n || dir != row[col]) { // 当前列的值与相邻列的值不等即为V形
                    col = -1;
                    break;
                }
            }
            ans[j] = col;
        }
        return ans;
    }
};