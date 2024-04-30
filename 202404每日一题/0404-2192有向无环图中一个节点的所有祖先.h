#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> ans(n); // 每个节点祖先
        vector<vector<int>> graph(n); // 图
        vector<int> indeg(n); // 入度表

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) { // 无祖先节点
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) { // u->v
                ans[v].insert(u);
                for (int pre : ans[u]) { // u的祖先节点也是v的祖先节点
                    ans[v].insert(pre);
                }
                --indeg[v];
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            for (int j : ans[i]) {
                res[i].push_back(j);
            }
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }
};