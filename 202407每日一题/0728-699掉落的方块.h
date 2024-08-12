#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1] - 1;
            heights[i] = positions[i][1];
            for (int j = 0; j < i; j++) {
                int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1] - 1;
                if (left2 <= right1 && right2 >= left1) {
                    heights[i] = max(heights[i], heights[i] + heights[j]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            heights[i] = max(heights[i], heights[i - 1]);
        }
        return heights;
    }
};