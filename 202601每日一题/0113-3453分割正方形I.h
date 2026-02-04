#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxY = 0, totalArea = 0;
        for (auto& square : squares) {
            maxY = max(maxY, (double)(square[1] + square[2]));
            totalArea += (double)square[2] * square[2];
        }

        auto check = [&](double y) -> bool {
            double sumArea = 0;
            for (auto& square : squares) {
                if (square[1] < y) {
                    sumArea += square[2] * min(y - square[1], (double)square[2]);
                }
            }
            return sumArea >= totalArea / 2;
        };

        double left = 0, right = maxY;
        while (abs(right - left) > 1e-5) {
            double mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};