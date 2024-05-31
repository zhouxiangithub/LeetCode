#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        //定义 f[k][x1][x2] 表示两个人分别从 (x1, k−x1) 和 (x2, k−x2) 同时出发到达 (N−1, N−1) 摘到的樱桃个数之和的最大值
        vector<vector<vector<int>>> f(2 * n - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; k++) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); x1++) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); x2++) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; //都往右
                    if (x1) {
                        res = max(res, f[k - 1][x1 - 1][x2]); //往下往右
                    }
                    if (x2) {
                        res = max(res, f[k - 1][x1][x2 - 1]); //往右往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); //都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { //避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};