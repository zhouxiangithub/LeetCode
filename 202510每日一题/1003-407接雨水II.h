#pragma once
using namespace std;
#include <vector>
#include <queue>

typedef pair<int, int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) {
            return 0;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({ heightMap[i][j], i * n + j });
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dirs[] = { -1,0,1,0,-1 };
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int dx = curr.second / n + dirs[k];
                int dy = curr.second % n + dirs[k + 1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && !visit[dx][dy]) {
                    if (curr.first > heightMap[dx][dy]) {
                        res += curr.first - heightMap[dx][dy];
                    }
                    visit[dx][dy] = true;
                    pq.push({ max(curr.first, heightMap[dx][dy]), dx * n + dy });
                }
            }
        }
        return res;
    }
};