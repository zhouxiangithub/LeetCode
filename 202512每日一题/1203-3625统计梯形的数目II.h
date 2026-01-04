#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<float, vector<float>> kToB; // 斜率--截距--相同斜率线段的各种截距
        unordered_map<int, vector<float>> midToK; // 中点--斜率--相同中点线段的各种斜率
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x1 - x2, dy = y1 - y2;
                float k, b;
                if (x1 == x2) {
                    k = INT_MAX;
                    b = x1;
                }
                else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx; // y=k*(x-x1)+y1 令 x=0 求得 y 即为 b
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                kToB[k].push_back(b);
                midToK[mid].push_back(k);
            }
        }

        for (auto& [_, bVec] : kToB) {
            if (bVec.size() == 1) {
                continue;
            }
            unordered_map<float, int> cnt;
            for (float b : bVec) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                res += sum * count;
                sum += count;
            }
        }

        for (auto& [_, kVec] : midToK) {
            if (kVec.size() == 1) {
                continue;
            }
            unordered_map<float, int> cnt;
            for (float k : kVec) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                res -= sum * count;
                sum += count;
            }
        }

        return res;
    }
};