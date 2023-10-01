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
        //ɾ�����������޽�ҵ�Ҷ�ӽڵ�,ֱ���������е�Ҷ�ӽڵ㶼�Ǻ��н�ҵ�
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

        //ɾ���������е�Ҷ�ӽڵ�(����Ҷ�ӽڵ㶼�ǽ��),����ɾ������(����Ϊ2���ڵĽ�Ҿ����ռ�)
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