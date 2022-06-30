#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());
        int n = heights.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
            {
                ans++;
            }
        }
        return ans;
    }
};