#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minA = m, minB = n;
        for (const auto& op : ops) {
            minA = min(minA, op[0]);
            minB = min(minB, op[1]);
        }
        return minA * minB;
    }
};