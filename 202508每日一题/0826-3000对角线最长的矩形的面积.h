#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0, maxDiaSq = 0;
        for (const auto& dim : dimensions) {
            int area = dim[0] * dim[1], diaSq = dim[0] * dim[0] + dim[1] * dim[1];
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            }
            else if (diaSq == maxDiaSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};