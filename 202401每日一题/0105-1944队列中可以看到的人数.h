#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> stack;
        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int h = heights[i];
            while (!stack.empty() && h > stack.back())
            {
                stack.pop_back();
                res[i] += 1;
            }
            if (!stack.empty())
            {
                res[i] += 1;
            }
            stack.push_back(h);
        }

        return res;
    }
};