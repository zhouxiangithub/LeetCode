#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist2 = 0;
        if (xCenter<x1 || xCenter>x2)
        {
            dist2 += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
        }
        if (yCenter<y1 || yCenter>y2)
        {
            dist2 += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));
        }
        return dist2 <= radius * radius;
    }
};