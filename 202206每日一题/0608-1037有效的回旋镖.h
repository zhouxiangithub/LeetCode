#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1x2 = points[1][0] - points[0][0];
        int y1y2 = points[1][1] - points[0][1];
        int x1x3 = points[2][0] - points[0][0];
        int y1y3 = points[2][1] - points[0][1];
        return (x1x2 * y1y3 - x1x3 * y1y2) != 0;
    }
};