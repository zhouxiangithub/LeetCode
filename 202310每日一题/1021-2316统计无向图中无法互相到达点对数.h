#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto&& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<int> visited(n);
        long long ans = 0ll;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            queue<int> q;
            q.emplace(i);
            long long cnt = 0;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                cnt++;
                for (auto&& y : graph[x])
                {
                    if (y != i && !visited[y])
                    {
                        q.emplace(y);
                        visited[y] = 1;
                    }
                }
            }
            ans += cnt * (n - cnt);
        }
        return ans / 2;
    }
};