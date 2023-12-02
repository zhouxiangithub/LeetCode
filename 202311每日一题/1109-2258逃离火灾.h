#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    constexpr static int INF = 1e9;

    constexpr static int dirs[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        
        //ͨ��bfs���ÿ�������Ż��ʱ��
        bfs(grid, fireTime);

        //���ֲ����ҵ����ͣ��ʱ��
        int ans = -1;
        int low = 0, high = m * n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(grid, fireTime, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans >= m * n ? INF : ans;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& fireTime)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) //���
                {
                    q.emplace(i, j);
                    fireTime[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                    {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) //ǽ���߻��
                        {
                            continue;
                        }
                        q.emplace(nx, ny);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    bool check(vector<vector<int>>& grid, vector<vector<int>>& fireTime, int stayTime)
    {
        int m = fireTime.size(), n = fireTime[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, stayTime);
        visit[0][0] = true;

        while (!q.empty())
        {
            auto [cx, cy, time] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dirs[i][0];
                int ny = cy + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    if (grid[nx][ny] == 2 || visit[nx][ny])
                    {
                        continue;
                    }
                    //"="���ﰲȫ�ݺ�����ϵ���ȫ��
                    if (nx == m - 1 && ny == n - 1)
                    {
                        return time + 1 <= fireTime[nx][ny];
                    }
                    //�����л�δ���ﵱǰλ��
                    if (time + 1 < fireTime[nx][ny])
                    {
                        q.emplace(nx, ny, time + 1);
                        visit[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }
};