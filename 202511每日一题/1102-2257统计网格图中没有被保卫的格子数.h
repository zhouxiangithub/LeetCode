#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        queue<tuple<int, int, int>> q;
        vector<int> dx = { 0,0,-1,1 };
        vector<int> dy = { 1,-1,0,0 };

        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = -1; // 标记警卫
            for (int k = 0; k < 4; k++) {
                q.emplace(guard[0], guard[1], k);
            }
        }

        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = -2; // 标记墙体
        }

        while (!q.empty()) {
            auto [x, y, k] = q.front();
            q.pop();
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0) { // 下一个格子,不为警卫或墙体
                if ((grid[nx][ny] & (1 << k)) == 0) { // 未遍历
                    grid[nx][ny] |= (1 << k);
                    q.emplace(nx, ny, k);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};