#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
private:
    int encode(int u, int v, int n)
    {
        return u * n + v;
    }
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1], nodes = edge[2];
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        //used:key--uv边,value--该边上的可达细分节点数
        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachableNodes = 0;
        //pq:key--起点到该节点的路径长度,value--节点
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty() && pq.top().first <= maxMoves)
        {
            auto [step, u] = pq.top();
            pq.pop();
            if (visited.count(u))
            {
                continue;
            }
            visited.emplace(u);
            reachableNodes++;
            for (auto [v, nodes] : adList[u])
            {
                if (nodes + step + 1 <= maxMoves && !visited.count(v))
                {
                    pq.emplace(nodes + step + 1, v);
                }
                used[encode(u, v, n)] = min(nodes, maxMoves - step);
            }
        }

        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1], nodes = edge[2];
            reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
        }
        return reachableNodes;
    }
};