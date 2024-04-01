#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    using LL = long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long mod = 1e9 + 7;
        vector<vector<pair<int, int>>> e(n); //�ڽӱ�
        for (const auto& road : roads)
        {
            int x = road[0], y = road[1], t = road[2];
            e[x].emplace_back(y, t);
            e[y].emplace_back(x, t);
        }
        vector<LL> dis(n, LLONG_MAX);
        vector<LL> ways(n);

        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q; //(·������,��ı��)
        q.emplace(0, 0);
        dis[0] = 0; //Դ���㵱ǰ���·������
        ways[0] = 1; //Դ�������·����Ŀ

        while (!q.empty())
        {
            auto [l, u] = q.top();
            q.pop();
            if (l > dis[u])
            {
                continue;
            }
            for (auto& [v, t] : e[u])
            {
                if (l + t < dis[v])
                {
                    dis[v] = l + t;
                    ways[v] = ways[u];
                    q.emplace(l + t, v);
                }
                else if (l + t == dis[v])
                {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};