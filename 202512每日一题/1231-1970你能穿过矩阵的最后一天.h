#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    static constexpr int dirs[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int res = 0, left = 0, right = cells.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;

            vector<vector<int>> grid(row, vector<int>(col, 0)); // Â½µØ
            for (int i = 0; i < mid; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1; // Ë®Óò
            }

            queue<pair<int, int>> q;
            for (int i = 0; i < col; i++) {
                if (!grid[0][i]) {
                    q.emplace(0, i);
                    grid[0][i] = 1;
                }
            }

            bool flag = false;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = x + dirs[i][0];
                    int dy = y + dirs[i][1];
                    if (dx >= 0 && dx < row && dy >= 0 && dy < col && !grid[dx][dy]) {
                        if (dx == row - 1) {
                            flag = true;
                            break;
                        }
                        q.emplace(dx, dy);
                        grid[dx][dy] = 1;
                    }
                }
            }
            if (flag) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};