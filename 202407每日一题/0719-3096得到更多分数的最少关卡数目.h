#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int total = accumulate(possible.begin(), possible.end(), 0) * 2 - n;
        int preSum = 0;
        for (int i = 0; i < n - 1; i++) {
            preSum += possible[i] == 1 ? 1 : -1;
            if (2 * preSum > total) {
                return i + 1;
            }
        }
        return -1;
    }
};