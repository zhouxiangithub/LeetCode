#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int n = arrays[0].size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0][n - 1];
        for (int i = 1; i < arrays.size(); i++) {
            n = arrays[i].size();
            res = max(res, max(abs(arrays[i][n - 1] - minVal), abs(maxVal - arrays[i][0])));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i][n - 1]);
        }
        return res;
    }
};