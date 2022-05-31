#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
    利用广度优先搜索求出节点0到其它节点的最短距离。
    然后依次求出每个节点变为空闲的时间，当所有节点都变为空闲时，整个网络即变为空闲状态。
    因此网络的最早空闲时间即为各个节点中最晚的空闲时间。

    节点v每发送一次消息后，经过2*dist[v]秒后才能收到回复
    
    当2*dist[v]<=patience[v]时，节点v变为空闲的时间为：2*dist[v]+1
    当2*dist[v]>patience[v]时，
        会再发送 (2*dist[v]-1) / patience[v] 次消息
        最后一次发送消息的时间为：patience[v] * {(2*dist[v]-1) / patience[v]}
        最后一次收到回复的时间为：patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v]
        节点v变为空闲的时间为：patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v] + 1
    
    综上：
        节点v变为空闲的时间为：patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v] + 1
*/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n); //记录每个节点存在的相连节点
        vector<bool> visit(n, false);
        for (auto& v : edges)
        {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty())
        {
            int sz = qu.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = qu.front();
                qu.pop();
                for (auto& v : adj[curr])
                {
                    if (visit[v])
                    {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};