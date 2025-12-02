#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <unordered_map>

class DSU {
public:
    vector<int> parent;

    DSU(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void join(int u, int v) {
        parent[find(v)] = find(u);
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c + 1);
        for (auto& con : connections) {
            dsu.join(con[0], con[1]);
        }

        vector<bool> online(c + 1, true); // 起初电站均处于在线状态 
        vector<int> offlineCounts(c + 1, 0);
        unordered_map<int, int> minOnlineStations;

        for (auto& query : queries) {
            int op = query[0], x = query[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minOnlineStations.count(root)) {
                minOnlineStations[root] = -1;
            }

            int minStation = minOnlineStations[root];
            if (online[i]) {
                if (minStation == -1 || minStation > i) {
                    minOnlineStations[root] = i;
                }
            }
        }

        vector<int> res;

        for (int i = queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.find(x);
            int minStation = minOnlineStations[root];

            if (op == 1) {
                if (online[x]) {
                    res.push_back(x);
                }
                else {
                    res.push_back(minStation);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                }
                else {
                    online[x] = true; // 倒序处理则下线变上线
                    if (minStation == -1 || minStation > x) {
                        minOnlineStations[root] = x;
                    }
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};