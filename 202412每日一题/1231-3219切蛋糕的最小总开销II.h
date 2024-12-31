#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        long long h = 1, v = 1;
        long long res = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty() || (!horizontalCut.empty() && horizontalCut.back() > verticalCut.back())) {
                res += horizontalCut.back() * h;
                horizontalCut.pop_back();
                v++;
            }
            else {
                res += verticalCut.back() * v;
                verticalCut.pop_back();
                h++;
            }
        }
        return res;
    }
};