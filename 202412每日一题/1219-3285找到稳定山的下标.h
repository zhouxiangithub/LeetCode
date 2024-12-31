#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > threshold) {
                res.push_back(i);
            }
        }
        return res;
    }
};