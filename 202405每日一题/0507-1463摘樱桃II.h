#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //定义 f[i][j1][j2] 表示当第一个机器人从 (0,0) 走到 (i,j1) 第二个机器人从 (0,n−1) 走到 (i,j2) 最多能收集的樱桃数目
        //f[i][..][..] 是由 f[i-1][..][..] 转移来的, 故将三维降成二维
        vector<vector<int>> f(n, vector<int>(n, -1)), g(n, vector<int>(n, -1));
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; i++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int best = -1;
                    for (int dj1 = j1 - 1; dj1 <= j1 + 1; dj1++) {
                        for (int dj2 = j2 - 1; dj2 <= j2 + 1; dj2++) {
                            if (dj1 >= 0 && dj1 < n && dj2 >= 0 && dj2 < n && f[dj1][dj2] != -1) {
                                best = max(best, f[dj1][dj2] + (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]));
                            }
                        }
                    }
                    g[j1][j2] = best; //自底向上
                }
            }
            swap(f, g);
        }

        int ans = 0;
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                ans = max(ans, f[j1][j2]);
            }
        }
        return ans;
    }
};