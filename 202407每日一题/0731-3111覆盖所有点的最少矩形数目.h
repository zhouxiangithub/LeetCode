#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 0;
        int bound = -1;
        for (auto& point : points) {
            if (point[0] > bound) {
                bound = point[0] + w;
                res++;
            }
        }
        return res;
    }
};