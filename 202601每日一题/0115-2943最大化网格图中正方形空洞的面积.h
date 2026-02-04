#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hCur = 1, hMax = 1;
        int vCur = 1, vMax = 1;
        for (int i = 0; i < hBars.size() - 1; i++) {
            if (hBars[i + 1] == hBars[i] + 1) {
                hCur++;
            }
            else {
                hCur = 1;
            }
            hMax = max(hMax, hCur);

        }
        for (int i = 0; i < vBars.size() - 1; i++) {
            if (vBars[i + 1] == vBars[i] + 1) {
                vCur++;
            }
            else {
                vCur = 1;
            }
            vMax = max(vMax, vCur);
        }
        int side = min(hMax, vMax) + 1;
        return side * side;
    }
};