#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int find(vector<int>& uf, int u) {
        if (uf[u] == u) {
            return u;
        }
        uf[u] = find(uf, uf[u]);
        return uf[u];
    }

    void merge(vector<int>& uf, int u, int v) {
        int ru = find(uf, u), rv = find(uf, v);
        uf[ru] = rv;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();

        vector<int> initialSet(n);
        for (int v : initial) {
            initialSet[v] = 1;
        }

        vector<int> uf(n);
        iota(uf.begin(), uf.end(), 0);
        for (int u = 0; u < n; u++) {
            if (initialSet[u] == 1) {
                continue;
            }
            for (int v = 0; v < n; v++) {
                if (initialSet[v] == 1) {
                    continue;
                }
                if (graph[u][v] == 1) {
                    merge(uf, u, v);
                }
            }
        }

        vector<vector<int>> infectedBy(n);
        for (int v : initial) {
            vector<int> infectedSet(n);
            for (int u = 0; u < n; u++) {
                if (initialSet[u] == 1 || graph[u][v] == 0) {
                    continue;
                }
                infectedSet[find(uf, u)] = 1;
            }
            for (int u = 0; u < n; u++) {
                if (infectedSet[u] == 1) {
                    infectedBy[u].push_back(v);
                }
            }
        }

        vector<int> count(n);
        for (int u = 0; u < n; u++) {
            if (infectedBy[u].size() != 1) {
                continue;
            }
            int v = infectedBy[u][0];
            for (int w = 0; w < n; w++) {
                if (find(uf, w) == find(uf, u)) {
                    count[v]++;
                }
            }
        }

        int res = initial[0];
        for (int v : initial) {
            if (count[v] > count[res] || (count[v] == count[res] && v < res)) {
                res = v;
            }
        }

        return res;
    }
};