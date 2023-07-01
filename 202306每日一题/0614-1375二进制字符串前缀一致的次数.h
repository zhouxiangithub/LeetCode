#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int ans = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            //前i次翻转中下标的最大值等于i
            right = max(right, flips[i]);
            if (right == i + 1)
            {
                ans++;
            }
        }
        return ans;
    }
};