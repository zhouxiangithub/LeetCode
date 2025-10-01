#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
            });

        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            auto& pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < n; j++) {
                auto& pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin && pointB[1] < yMax) {
                    res++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
            }
        }
        return res;
    }
};