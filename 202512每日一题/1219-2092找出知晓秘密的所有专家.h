#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int mSize = meetings.size();
        sort(meetings.begin(), meetings.end(), [&](const auto& mt1, const auto& mt2) {
            return mt1[2] < mt2[2];
        });

        vector<int> knowSecret(n);
        knowSecret[0] = knowSecret[firstPerson] = true;

        for (int i = 0; i < mSize;) {
            // [i, j] 为同一时间
            int j = i;
            while (j + 1 < mSize && meetings[j + 1][2] == meetings[i][2]) {
                j++;
            }

            unordered_set<int> points; // 同一时间的点集
            unordered_map<int, vector<int>> edges;
            for (int k = i; k <= j; k++) {
                int x = meetings[k][0], y = meetings[k][1];
                points.insert(x);
                points.insert(y);
                edges[x].push_back(y);
                edges[y].push_back(x);
            }

            queue<int> que; // 知晓秘密的点集
            for (int point : points) {
                if (knowSecret[point]) {
                    que.push(point);
                }
            }

            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int v : edges[u]) {
                    if (!knowSecret[v]) {
                        knowSecret[v] = true;
                        que.push(v);
                    }
                }
            }

            i = j + 1;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (knowSecret[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};