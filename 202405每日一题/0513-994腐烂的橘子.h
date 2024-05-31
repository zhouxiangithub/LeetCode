#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    int fresh_cnt;
    int dis[10][10];
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        memset(dis, -1, sizeof(dis));
        fresh_cnt = 0;
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
                else if (grid[i][j] == 1) {
                    fresh_cnt++;
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n || ~dis[dx][dy] || grid[dx][dy] != 1) {
                    continue;
                }
                grid[dx][dy] = 2;
                dis[dx][dy] = dis[x][y] + 1;
                q.emplace(dx, dy);
                fresh_cnt--;
                ans = dis[dx][dy];
                if (!fresh_cnt) {
                    break;
                }
            }
        }
        return fresh_cnt ? -1 : ans;
    }
};