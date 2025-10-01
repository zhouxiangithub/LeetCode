#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            auto& pointA = points[i];
            for (int j = 0; j < n; j++) {
                auto& pointB = points[j];
                if (i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                if (n == 2) {
                    res++;
                    continue;
                }

                bool flag = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    auto& pointC = points[k];
                    if ((pointC[0] >= pointA[0] && pointC[1] <= pointA[1]) && (pointC[0] <= pointB[0] && pointC[1] >= pointB[1])) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    res++;
                }
            }
        }
        return res;
    }
};