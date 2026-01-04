#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // 每列 x 的最大最小值
        vector<int> maxRow(n + 1, 0);
        vector<int> minRow(n + 1, n + 1);
        // 每行 y 的最大最小值
        vector<int> maxCol(n + 1, 0);
        vector<int> minCol(n + 1, n + 1);

        for (auto& build : buildings) {
            int x = build[0], y = build[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int res = 0;
        for (auto& build : buildings) {
            int x = build[0], y = build[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
                res++;
            }
        }
        return res;
    }
};