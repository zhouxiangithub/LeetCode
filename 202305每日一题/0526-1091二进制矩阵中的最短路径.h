#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
        {
            return -1;
        }
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        dist[0][0] = 1;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1)
            {
                return dist[x][y];
            }
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) //Խ��
                    {
                        continue;
                    }
                    if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] <= dist[x][y] + 1) //��Ԫ��ֵ��Ϊ0���ѱ�����
                    {
                        continue;
                    }
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                    q.push({ x + dx,y + dy });
                }
            }
        }
        return -1;
    }
};