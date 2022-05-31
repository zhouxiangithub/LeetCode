#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
    设两个叶子节点的最长距离为maxdist，可以得到的结论为：
    最小高度树的高度为 maxdist/2 向上取整，(maxdist+1)/2，且最小高度树的根节点一定存在其最长路径上。

    因此，我们只需要求出路径最长的两个叶子节点即可，并求出其路径的最中间的节点即为最小高度树的根节点。

    1)以任意节点p出发，利用广度优先搜索或者深度优先搜索找到以p为起点的最长路径的终点x；
    2)以节点x出发，找到以x为起点的最长路径的终点y；
    3)x到y之间的路径即为图中的最长路径，找到路径的中间节点即为根节点。
*/
class Solution {
public:
    //广度优先搜索
    int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj)
    {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;

        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto& v : adj[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
        {
            return { 0 };
        }
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        
        //找到与节点0最远的节点x
        int x = findLongestNode(0, parent, adj);
        
        //找到与节点x最远的节点y
        int y = findLongestNode(x, parent, adj);

        //求出节点x到节点y的路径
        vector<int> path;
        parent[x] = -1;
        while (y != -1)
        {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0)
        {
            return { path[m / 2 - 1], path[m / 2] };
        }
        else
        {
            return { path[m / 2] };
        }
    }
};