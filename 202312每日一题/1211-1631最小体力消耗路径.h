#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int left = 0, right = 999999, ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            queue<pair<int, int>> qu;
            qu.emplace(0, 0);
            vector<int> seen(m * n);
            seen[0] = 1;
            while (!qu.empty())
            {
                auto [x, y] = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++)
                {
                    int mx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (mx >= 0 && mx < m && ny >= 0 && ny < n && !seen[mx * n + ny] && abs(heights[x][y] - heights[mx][ny]) <= mid)
                    {
                        qu.emplace(mx, ny);
                        seen[mx * n + ny] = 1;
                    }
                }
            }
            if (seen[m * n - 1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
