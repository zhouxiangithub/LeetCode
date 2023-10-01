#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (const auto& edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
            degree[x] ++;
            degree[y]++;
        }

        int rest = n;
        //删除树中所有无金币的叶子节点,直到树中所有的叶子节点都是含有金币的
        {
            queue<int> q;
            for (int i = 0; i < n; i++)
            {
                if (degree[i] == 1 && !coins[i])
                {
                    q.push(i);
                }
            }
            while (!q.empty())
            {
                int u = q.front();
                degree[u]--;
                q.pop();
                rest--;
                for (int v : g[u])
                {
                    degree[v]--;
                    if (degree[v] == 1 && !coins[v])
                    {
                        q.push(v);
                    }
                }
            }
        }

        //删除树中所有的叶子节点(现在叶子节点都是金币),连续删除两次(步长为2以内的金币均可收集)
        {
            for (int times = 0; times < 2; times++)
            {
                queue<int> que;
                for (int i = 0; i < n; i++)
                {
                    if (degree[i] == 1)
                    {
                        que.push(i);
                    }
                }
                while (!que.empty())
                {
                    int u = que.front();
                    degree[u]--;
                    que.pop();
                    rest--;
                    for (int v : g[u])
                    {
                        degree[v]--;
                    }
                }
            }
        }

        return rest == 0 ? 0 : 2 * (rest - 1);
    }
};