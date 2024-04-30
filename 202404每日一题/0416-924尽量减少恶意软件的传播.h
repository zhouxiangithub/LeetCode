#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> ids(n); // 将节点分组,节点所在连通分量的编号
        unordered_map<int, int> id_to_size; // 每个节点组的大小,各个连通分量中节点的数量
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (!ids[i]) {
                ids[i] = ++id;
                int size = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v = 0; v < n; v++) {
                        if (!ids[v] && graph[u][v] == 1) {
                            size++;
                            q.push(v);
                            ids[v] = id;
                        }
                    }
                }
                id_to_size[id] = size;
            }
        }

        unordered_map<int, int> id_to_initials; // 每个连通分量初始时被感染节点的数量
        for (int ini : initial) {
            id_to_initials[ids[ini]]++;
        }

        int ans = n + 1, ans_removed = 0;
        for (int ini : initial) {
            // 若某个连通分量恰有一个节点被感染,则移除该节点即可减少该连通分量中节点数量个感染节点
            int removed = (id_to_initials[ids[ini]] == 1 ? id_to_size[ids[ini]] : 0);
            if (removed > ans_removed || (removed == ans_removed && ini < ans)) {
                ans = ini;
                ans_removed = removed;
            }
        }
        return ans;
    }
};